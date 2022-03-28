from neuron import h
import numpy as np
from utils import add_channels, load_3d_morphology


class Golgi():
    def __repr__(self):
        return f'Golgi_morpho{self._morpho}[{self._id}]'

    def __init__(self, _id, morpho=1):
        self._id = _id
        self._morpho = morpho

        # Load the cell's 3D morphology
        load_3d_morphology(self, f'morphology/pair-140514-C2-1_split_{morpho}.asc')

        # Load conductance parameters
        conductances = np.genfromtxt(f"Optimization_result {morpho}.txt")
        soma_params   = {"gmax_Leak": 0.00003, "TotalPump_cdp5StCmod": 1e-7} | dict(zip(("gbar_Nav1_6", "gbar_Kv1_1", "gkbar_Kv3_4", "gkbar_Kv4_3", "gbar_Kca1_1", "gkbar_Kca3_1", "gcabar_GRC_CA", "pcabar_Cav3_1"), conductances[9:17]))
        apical_params = {"gmax_Leak": 0.00003, "TotalPump_cdp5StCmod": 5e-9} | dict(zip(("gbar_Nav1_6", "gbar_Kca1_1", "gkbar_Kca2_2", "gcabar_Cav2_3", "pcabar_Cav3_1"), conductances[0:5]))
        basal_params  = {"gmax_Leak": 0.00003, "TotalPump_cdp5StCmod": 2e-9} | dict(zip(("gbar_Nav1_6", "gbar_Kca1_1", "gkbar_Kca2_2", "gcabar_GRC_CA"), conductances[5:9]))
        ais_params    = {"gmax_Leak": 0.00003, "TotalPump_cdp5StCmod": 1e-8} | dict(zip(("gbar_HCN1", "gbar_HCN2", "gbar_Nav1_6", "gkbar_GRC_KM", "gbar_Kca1_1", "gcabar_GRC_CA"), conductances[17:23]))
        axon_params   = {"gmax_Leak": 0.000001, "TotalPump_cdp5StCmod": 1e-8, "gbar_Nav1_6": 0.0115, "gkbar_Kv3_4": 0.0091} | dict(zip(("gbar_Nav1_6", "gkbar_Kv3_4"), conductances[23:25]))
        rev_potentials = {"e_Leak": -55, "ena": 60, "ek": -80, "eca": 137}

        # Soma
        self.soma[0].nseg = 1 + 2 * int(self.soma[0].L / 40)
        self.soma[0].Ra = 122
        self.soma[0].cm = 1
        add_channels(self.soma[0], ('Leak', 'Nav1_6', 'Kv1_1', 'Kv3_4', 'Kv4_3', 'Kca1_1', 'Kca3_1', 'GRC_CA', 'Cav3_1', 'cdp5StCmod'), soma_params, rev_potentials)

        # Dendrites
        for dend in self.dend:
            dend.nseg = 1 + 2 * int(dend.L / 40)
            dend.Ra = 122
            dend.cm = 2.5

        # Separate out dendrite types
        if morpho == 1:
            basal_indices = get_indices_in_ranges(range(0, 4), range(16, 18), range(33, 42), range(84, 85), range(105, 151))
            mf_aa_indices = get_indices_in_ranges(range(108, 113), range(114, 122), range(128, 130), range(131, 133), range(135, 141), range(144, 146), range(147, 151))
        elif morpho == 2:
            basal_indices = get_indices_in_ranges(range(0, 1), range(75, 76), range(103, 126), range(153, 168))
            mf_aa_indices = get_indices_in_ranges(range(105, 108), range(110, 114), range(115, 120), range(123, 125), range(154, 161), range(162, 168))

        self.dendbasal = [self.dend[i] for i in basal_indices]
        self.dendapical = [self.dend[i] for i in range(len(self.dend)) if i not in basal_indices]
        self.dend_pf = self.dendapical[:]
        self.dend_aa_mf = [self.dend[i] for i in mf_aa_indices]

        # Apical Dendrites
        for dend in self.dendapical:
            add_channels(dend, ('Leak', 'Nav1_6', 'Kca1_1', 'Kca2_2', 'Cav2_3', 'Cav3_1', 'cdp5StCmod'), apical_params, rev_potentials)

        # Basal Dendrites
        for dend in self.dendbasal:
            add_channels(dend, ('Leak', 'Nav1_6', 'Kca1_1', 'Kca2_2', 'GRC_CA', 'cdp5StCmod'), basal_params, rev_potentials)

        # Axon
        for i,axon in enumerate(self.axon):
            axon.nseg = 1 + int(self.axon[i].L / 40)
            axon.Ra = 122
            axon.cm = 1
            if i == 0: # AIS
                add_channels(self.axon[0], ('Leak', 'HCN1', 'HCN2', 'Nav1_6', 'GRC_KM', 'Kca1_1', 'GRC_CA', 'cdp5StCmod'), ais_params, rev_potentials)
            else:
                add_channels(self.axon[i], ('Leak', 'Nav1_6', 'Kv3_4', 'cdp5StCmod'), axon_params, rev_potentials)

        # Setup recordings
        self.nc_spike = h.NetCon(self.soma[0](1)._ref_v, None, -20, 0.1, 1, sec=self.soma[0])
        self.vm = h.Vector()
        self.vm.record(self.soma[0](0.5)._ref_v)

    def createsyn(self, pf_n, mf_n, aa_n):
        from Synapse import Synapse

        # PF
        self.L_PF = [Synapse('PF_AMPA', self, self.dend_pf[i%len(self.dend_pf)]) for i in range(0, pf_n)]
        self.L_PF_NMDA = [Synapse('PF_NMDA', self, self.dend_pf[i%len(self.dend_pf)]) for i in range(0, pf_n)]
        
        # MF
        self.L_MF_NMDA_B = [Synapse('MF_NMDA_B', self, self.dend_aa_mf[i%len(self.dend_aa_mf)]) for i in range(0, mf_n)]
        self.L_MF_AMPA = [Synapse('MF_AMPA', self, self.dend_aa_mf[i%len(self.dend_aa_mf)]) for i in range(0, mf_n)]

        # AA
        self.L_AA = [Synapse('AA_AMPA', self, self.dend_aa_mf[i%len(self.dend_aa_mf)]) for i in range(0, aa_n)]
        self.L_AA_NMDA_B = [Synapse('MF_NMDA_B', self, self.dend_aa_mf[i%len(self.dend_aa_mf)]) for i in range(0, aa_n)]  # TODO: MF_NMDA_B?


def get_indices_in_ranges(*ranges):
    return [i for rng in ranges for i in rng]
