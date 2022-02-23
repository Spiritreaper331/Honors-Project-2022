
import math
from neuron import h

h.load_file("stdrun.hoc")

h.v_init = -80
h.tstop = 420100
h.celsius = 30

h.dt = 0.005  #0.01?
h.cvode.active(1)
h.cvode.atol(1e-5)

nsyn1 = 4
ncells = 1  # There is code that assumes this is 1 (in the original code too)
nmossy = 4  # There is code that assumes this equals be nsyn1 (in the original code too)
NumSyn = 2  # This value turns off mossy fibers above that value
            # This can be changed at runtime if either the LTP() or LTD() function is called afterwards

# Single compartment cell
class Grc:
    def __init__(self, nsyn):
        self.soma = soma = h.Section(name='soma')
        soma.nseg = 1
        soma.diam = 9.772
        soma.L = 9.772
        soma.cm = 1
        soma.Ra = 100
        #soma.Area = math.pi*soma.diam*soma.L*1e-8  # TODO: where is this used? (not a normal NEURON section field)

        soma.insert('GrC_Lkg1')
        soma.insert('GrG_Na')
        soma.insert('GrG_Nar')
        soma.insert('GrG_KV')
        soma.insert('GrC_KA')
        soma.insert('GrC_Kir')
        soma.insert('GrC_KCa')
        soma.insert('GrC_CaHVA')
        soma.insert('Calc')
        soma.insert('GrC_pNa')
        soma.insert('GrG_KM')
        soma.insert('GrC_Lkg2')

        soma.ena = 87.39
        soma.ek = -84.69
        # soma.cao0_ca_ion = 2  # TODO: these don't seem to be used either
        # soma.cai0_ca_ion = 0.0001
        # soma.ecl = -65

        # Soma conductances that can be modified:
        #   gnabar_GrG_Na, gnabar_GrC_pNa, Aalpha_m_GrC_pNa, Abeta_m_GrC_pNa, gnabar_GrG_Nar,
        #   gkbar_GrG_KV, gkbar_GrC_KA, Aalpha_a_GrC_KA, Abeta_a_GrC_KA, gkbar_GrC_Kir, gkbar_GrC_KCa,
        #   gcabar_GrC_CaHVA, gkbar_GrG_KM (gKSlowbar), gl_GrC_Lkg1 (gLeakage), ggaba_GrC_Lkg2 (gGabaA)
        # Soma calcium parameters that can be modified:
        #   d_Calc (shell thickness), cai0_Calc (initial concentration), beta_Calc (removal rate)

        self.stim0 = h.IClamp(soma(0.5))
        self.stim0.delay = 1000 # TODO: possibly customize these values
        self.stim0.dur = 4000
        self.stim0.amp = 0.00733

        # Syn1 has the following modifiable parameters for short-term plasticity
        #   taurec (tau recovery, ms), taufacil (tau facilitation, ms), tauin (tau decay, ms), usr (use of resources by each AP), u0 (initial facilitated use)
        self.syn1 = [h.GrC_Glu1(soma(0.5)) for _ in range(nsyn)]

        # AMPA has the following modifiable parameters for long-term plasticity
        #   freqdel (nA^-1)
        # AMPA has the following modifiable parameters for voltage-dependent and synaptic conductances
        #   cam_4_3 (C1C2, mM^-1 ms^-1), cam_3_2 (C2C3, mM^-1 ms^-1), cam_7_6 (D1D2, mM^-1 ms^-1)
        #   cam_1_5 (OD3, ms^-1), cam_1_2 (OC3, ms^-1), cam_2_1 (C3O, ms^-1), cam_2_3 (C3C2, ms^-1), cam_2_6 (C3D2, ms^-1), cam_3_4 (C2C1, ms^-1), cam_3_7 (C2D1, ms^-1),
        #   cam_5_1 (D3O, ms^-1), cam_6_2 (D2C3, ms^-1), cam_6_7 (D2D1, ms^-1), cam_7_3 (D1C2, ms^-1), cam_6_5 (D2D3, ms^-1), cam_5_6 (D3D2, ms^-1),
        #   gbarampa (Gmax, usiemens)
        self.ampa = [h.GrC_AMPA(soma(0.5)) for _ in range(nsyn)]

        # NMDA has the following modifiable parameters for long-term plasticity
        #   freqdel (nA^-1)
        # NMDA has the following modifiable parameters for voltage-dependent and synaptic conductances
        #   cnm_4_3 (C1C2, ms^-1 uM^1), cnm_3_4 (C2C1, ms^-1), cnm_3_2 (C2C3, ms^-1 uM^1), cnm_2_3 (C3C2, ms^-1),
        #   cnm_2_1 (C3O, ms^-1),  cnm_1_2 (OC3, ms^-1), cnm_2_5 (C3D, ms^-1), cnm_5_2 (DC3, ms^-1),
        #   gbarnmda (Gmax2, pS), v0_block (V0 Block, mV), alpha_vspom (Alpha Block, mV), Erev (mV)
        self.nmda = [h.GrC_NMDA(soma(0.5)) for _ in range(nsyn)]

        # LTP1 has the following modifiable parameters for long-term plasticity
        #   gamma (ms^-1), eta (ms^-1), nu1 (ms^-1), nu2 (ms^-1), pp (ms^-1), pd (ms^-1), gdel1 (nA^-1 ms^-1), gdel2 (nA^-1 ms^-1), Mp (nA/ms), Md (nA/ms), Ap (nA^2), Ad (nA^2)
        self.ltp1 = [h.Gr_LTP1(soma(0.5)) for _ in range(nsyn)]

        # Link all of the variables in the synapse channels
        for syn1, ampa, nmda, ltp1 in zip(self.syn1, self.ampa, self.nmda, self.ltp1):
            h.setpointer(nmda._ref_icanmda, "picanmda", ltp1)
            h.setpointer(ltp1._ref_Np, "pNp", nmda)
            h.setpointer(ltp1._ref_Np, "pNp", ampa)
            h.setpointer(ltp1._ref_Nd, "pNd", nmda)
            h.setpointer(ltp1._ref_Nd, "pNd", ampa)
            h.setpointer(syn1._ref_glu, "pglu", nmda)
            h.setpointer(syn1._ref_glu, "pglu", ampa)

    def connect2target(self, target):
        return h.NetCon(self.soma(1).v_ref, target)


# Create an artifical cell for use with point-processing
acell_home_ = h.Section('acell_home_')

class S1Gen:
    def __init__(self):
        # This mossy fiber spike generator has the following modifiable parameters:
        #   t01 (first spike time)
        #   t02 (last spike time)
        #   fast_freq (interspike frequency, Hz)
        #   slow_freq (interburst frequency, Hz)
        #   APinburst (spikes per burst)
        #   startbursting (begin of the input, ms)
        #   endbursting (end of the input, ms)
        #   noise (poisson noise, 0 means none)
        global acell_home_
        self.pp = h.SpGen2(acell_home_(0.5))

    def connect2target(self, target):
        return h.NetCon(self.pp, target)

    def turn_off(self):
        # This stops the mossy fiber from spiking
        self.pp.t01 = -1
        self.pp.t02 = -1
        self.pp.APinburst = 0


# Create the cells
GrCell = [Grc(nsyn1) for _ in range(ncells)]
Mossy = [S1Gen() for _ in range(nmossy)]


# These two functions setup the mossy fiber cells into one of two example patterns
# NOTE: The LTP version is the default settings, so if nothing is done those are the settings used
def LTP():
    # LTP after 4 bursts at 100 Hz
    for mossy in Mossy[:NumSyn]:
        mossy.pp.t01 = 20
        mossy.pp.t02 = 420000
        mossy.pp.fast_freq = 100
        mossy.pp.slow_freq = 4
        mossy.pp.APinburst = 10
        mossy.pp.startbursting = 2000
        mossy.pp.endbursting = 3000
    for mossy in Mossy[NumSyn:]: mossy.turn_off()

def LTD():
    # LTD after continuous stimulation at 2 Hz
    for mossy in Mossy[:NumSyn]:
        mossy.pp.t01 = 20
        mossy.pp.t02 = 420000
        mossy.pp.fast_freq = 2
        mossy.pp.slow_freq = 0
        mossy.pp.APinburst = 10
        mossy.pp.startbursting = 2000
        mossy.pp.endbursting = 3500
    for mossy in Mossy[NumSyn:]: mossy.turn_off()


# Network instantiation
def make_connection(src, target, weight=0.5, delay=0):
    netcon = src.connect2target(target)
    netcon.weight[0] = weight  # TODO: why the [0] to make this work?
    netcon.delay = delay
    return netcon
nclist = [make_connection(mossy, syn) for mossy, syn in zip(Mossy, GrCell[0].syn1)]


# Setup recordings
def record(ref):
    vec = h.Vector()
    vec.record(ref)
    return vec
t_vec = record(h._ref_t)
mossy_fiber_firing_recordings = [record(mossy.pp._ref_y) for mossy in Mossy]
GrC_voltage_recording = record(GrCell[0].soma(0.5)._ref_v)
GrCell_ltp1_messenger_recording = record(GrCell[0].ltp1[0]._ref_messenger)
GrCell_ltp1_Np_recording = record(GrCell[0].ltp1[0]._ref_Np)
GrCell_ltp1_Nd_recording = record(GrCell[0].ltp1[0]._ref_Nd)


# Run the simulation
LTD()
h.finitialize(h.v_init)
h.run()


# Plot the results
import matplotlib.pyplot as plt

plt.figure()
plt.title("Mossy Fibers")
for i, recording in enumerate(mossy_fiber_firing_recordings):
    plt.plot(t_vec, recording, label=f"#{i}")
plt.legend()
plt.xlabel("Time (ms)")
plt.ylim([0, 30])
plt.xlim([0, 4000])

plt.figure()
plt.title("GrC Membrane Potential")
plt.plot(t_vec, GrC_voltage_recording)
plt.xlabel("Time (ms)")
plt.ylabel("Membrane Potential (mV)")

plt.figure()
plt.title("LTP1 Messenger")
plt.plot(t_vec, GrCell_ltp1_messenger_recording)
plt.xlabel("Time (ms)")

plt.figure()
plt.title("LTP1 Np and Nd")
plt.plot(t_vec, GrCell_ltp1_Np_recording, label="Np")
plt.plot(t_vec, GrCell_ltp1_Nd_recording, label="Nd")
plt.legend()
plt.xlabel("Time (ms)")

plt.show()
