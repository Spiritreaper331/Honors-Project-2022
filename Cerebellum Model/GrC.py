"""
Granule cell model 2020. Includes regular, mild, adapting, and accelerate.

Modified by Tyler Rivera and Jeffrey Bush, Moravian University.

Authors: Stefano Masoli* 1, Marialuisa Tognolina* 1, Umberto Laforenza 2, Francesco Moccia 3, Egidio D'Angelo 1,4
Author information: 1 Department of Brain and Behavioral Sciences, University of Pavia, Via Forlanini 6, I-27100, Pavia, Italy,
2 Department of Molecular Medicine, University of Pavia, Via Forlanini 6, I-27100, Pavia, Italy,
3 Department of Biology and Biotechnology, University of Pavia, Via Forlanini 6, I-27100, Pavia, Italy,
4 Brain Connectivity Center, IRCCS Mondino Foundation, Via Mondino 2, I-27100, Pavia, Italy,
* Co-Author

Citation: Masoli S.*, Tognolina M.*, Laforenza U., Moccia F., D’Angelo E. Parameter tuning differentiates granule cell subtypes enriching transmission properties at the cerebellum input stage. Nature communication biology 2020.

DOI: 10.1038/s42003-020-0953-x
"""

import copy
from neuron import h
from utils import add_channels, create_section, load_3d_morphology

GrC_params = {
    "regular": {
        "soma": {"gmax_Leak": 0.00029038073716, "gkbar_Kv3_4": 0.00076192450951999995, "gkbar_Kv4_3": 0.0028149683906099998, "gkbar_Kir2_3": 0.00074725514701999996, "gcabar_GRC_CA": 0.00060938071783999998, "gbar_Kv1_1": 0.0056973826455499997, "gKur_Kv1_5": 0.00083407556713999999, "gKv2_2bar_Kv2_2_0010": 1.203410852e-05},
        "dend": {"gmax_Leak": 0.00025029700736999997, "gcabar_GRC_CA": 0.0050012800845900002, "gbar_Kca1_1": 0.010018074546510001, "gbar_Kv1_1": 0.00381819207934},
        "axon": {"gmax_Leak": 0.00036958189720000001, "gnabar_GRC_NA_FHF": 0.0092880585146199995, "gkbar_Kv3_4": 0.020373463109149999, "gcabar_GRC_CA": 0.00057726155447},
        "ais":  {"gnabar_GRC_NA_FHF": 1.28725006737226, "gkbar_Kv3_4": 0.0064959534065400001, "gmax_Leak": 0.00029276697557000002, "gcabar_GRC_CA": 0.00031198539471999999, "gkbar_GRC_KM": 0.00056671971737000002},
        "aa":   {"gnabar_GRC_NA": 0.026301636815019999, "gkbar_Kv3_4": 0.00237386061632, "gmax_Leak": 9.3640921249999996e-05, "gcabar_GRC_CA": 0.00068197420273000001},
        "pf":   {"gnabar_GRC_NA": 0.017718484492610001, "gkbar_Kv3_4": 0.0081756804703699993, "gmax_Leak": 3.5301616000000001e-07, "gcabar_GRC_CA": 0.00020856833529999999},
    },
    "mild": {
        "soma": {"gmax_Leak": 0.00020821612897999999, "gkbar_Kv3_4": 0.00053837153610999998, "gkbar_Kv4_3": 0.0032501728450999999, "gkbar_Kir2_3": 0.00080747403035999997, "gcabar_GRC_CA": 0.00066384354030999998, "gbar_Kv1_1": 0.0046520692281700003, "gKur_Kv1_5": 0.00106988075956, "gKv2_2bar_Kv2_2_0010": 2.5949576899999998e-05},
        "dend": {"gmax_Leak": 0.00020424219215, "gcabar_GRC_CA": 0.01841833779253, "gbar_Kca1_1": 0.02998872868395, "gbar_Kv1_1": 0.00010675447184},
        "axon": {"gmax_Leak": 0.00025295417368000002, "gnabar_GRC_NA_FHF": 0.011082499796400001, "gkbar_Kv3_4": 0.050732563882920002, "gcabar_GRC_CA": 0.00028797253573000002},
        "ais":  {"gnabar_GRC_NA_FHF": 1.28725006737226, "gkbar_Kv3_4": 0.034592458064240002, "gmax_Leak": 0.00025011065810000001, "gcabar_GRC_CA": 0.00011630629281, "gkbar_GRC_KM": 0.00044764153078999998},
        "aa":   {"gnabar_GRC_NA": 0.026301636815019999, "gkbar_Kv3_4": 0.0046029972380800003, "gmax_Leak": 7.8963697590000003e-05, "gcabar_GRC_CA": 0.00059214434259999998},
        "pf":   {"gnabar_GRC_NA": 0.01896618618573, "gkbar_Kv3_4": 0.0094015060525799998, "gmax_Leak": 4.1272473000000001e-07, "gcabar_GRC_CA": 0.00064742320254000001},
    },
    "adapting": {
        "soma": {"gmax_Leak": 0.00027672909671000001, "gkbar_Kv3_4": 0.00373151328841, "gkbar_Kv4_3": 0.0027313162972600002, "gkbar_Kir2_3": 0.00094360184424999995, "gcabar_GRC_CA": 0.00029165028328999998, "gbar_Kv1_1": 0.0031675812802999998, "gKur_Kv1_5": 0.00107176612352, "gKv2_2bar_Kv2_2_0010": 6.710092624e-05},
        "dend": {"gmax_Leak": 0.00029871180381000001, "gcabar_GRC_CA": 0.024687091736070001, "gbar_Kca1_1": 0.01185742892862, "gbar_Kv1_1": 0.00015853886699000001},
        "axon": {"gmax_Leak": 0.00031475453130000002, "gnabar_GRC_NA_FHF": 0.020910983616370001, "gkbar_Kv3_4": 0.03097630887484, "gcabar_GRC_CA": 0.00019803691988000001},
        "ais":  {"gnabar_GRC_NA_FHF": 1.5810107836409499, "gkbar_Kv3_4": 0.039582385081389997, "gmax_Leak": 0.00025512657995000002, "gcabar_GRC_CA": 0.00038160760886000002, "gkbar_GRC_KM": 0.00049717923887},
        "aa":   {"gnabar_GRC_NA": 0.025441894508310001, "gkbar_Kv3_4": 0.0046504514953399998, "gmax_Leak": 5.3037170669999997e-05, "gcabar_GRC_CA": 0.00031374692347000001},
        "pf":   {"gnabar_GRC_NA": 0.0142518259615, "gkbar_Kv3_4": 0.0098649550733799999, "gmax_Leak": 1.4118927999999999e-07, "gcabar_GRC_CA": 0.00024821458382999999},
    }
}
GrC_params["accelerate"] = copy.deepcopy(GrC_params["regular"].copy())
GrC_params["accelerate"]["pf"]["gmax_Leak"] = 1.4118927999999999e-07  # TODO: for pf 2 only?
GrC_params["accelerate"]["dend"]["gtrp_Ubc_TRP"] = 0.0005
GrC_rev_potentials = { "e_Leak": -60, "ek": -88, "ena": 87.39, "eca": 137.5}


class GrC():
    def __repr__(self):
        return f'GrC_{self._subtype}[{self._id}]'

    def __init__(self, _id, subtype):
        self._id = _id
        self._subtype = subtype

        # Load the cell's 3D morphology
        load_3d_morphology(self, 'morphology/GrC2020.asc')

        params = GrC_params[subtype]
        ca_ion_accum = 'cdp5_CR_CAM' if subtype == "accelerate" else 'cdp5_CR'

        # Soma channels
        self.soma[0].nseg = 1 + 2 * int(self.soma[0].L / 40)
        self.soma[0].Ra = 100
        self.soma[0].cm = 2
        add_channels(self.soma[0], ('Leak', 'Kv3_4', 'Kv4_3', 'Kir2_3', 'GRC_CA', 'Kv1_1', 'Kv1_5', 'Kv2_2_0010', ca_ion_accum), params["soma"], GrC_rev_potentials)

        # Dendrites
        channels = ('Leak', 'GRC_CA', 'Kca1_1', 'Kv1_1', ca_ion_accum)
        if 'gtrp_Ubc_TRP' in params["dend"]:
            channels += ('Ubc_TRP',)
        for dend in self.dend:
            dend.nseg = 1 + 2 * int(dend.L / 40)
            dend.Ra = 100
            dend.cm = 2.5
            add_channels(dend, channels, params["dend"], GrC_rev_potentials)

        # Hilock
        self.axon = create_section('hilock', self, 1, 1.5, cm=2, start=(0.0, 5.62232), end=(0.0, 6.62232))
        self.axon.connect(self.soma[0], 0, 0)
        add_channels(self.axon, ('Leak', 'GRC_NA_FHF', 'Kv3_4', 'GRC_CA', ca_ion_accum), params["axon"], GrC_rev_potentials)

        # Axon Initial Segment (AIS)
        self.ais = create_section('ais', self, 10, 0.7, start=(0.0, 6.62232), end=(0.0, 16.62232))
        self.ais.connect(self.axon, 1, 0)
        add_channels(self.ais, ('GRC_NA_FHF', 'Kv3_4', 'Leak', 'GRC_CA', 'GRC_KM', ca_ion_accum), params["ais"], GrC_rev_potentials)

        # Ascending Axons (AA)
        length_of_sections = 7
        num_aa_sections = 126//length_of_sections
        self.HD_aa = []
        start = 16.62232  # TODO: was in the loop, but that defeats its purpose
        for i in range(num_aa_sections):
            aa_section = create_section(f'aa_{i}', self, length_of_sections, 0.3, start=(0.0, start+length_of_sections*i), end=(0.0, start+length_of_sections*(i+1)))
            add_channels(aa_section, ('Leak', 'GRC_NA', 'Kv3_4', 'GRC_CA', ca_ion_accum), params["aa"], GrC_rev_potentials)
            aa_section.connect(self.HD_aa[-1] if i > 0 else self.ais, 1, 0)
            self.HD_aa.append(aa_section)

        # Parallel Fibers (PF)
        num_pf = 2
        num_pf_sections = 1000//length_of_sections
        self.HD_pf = [[] for j in range(num_pf)]
        for j, pf in enumerate(self.HD_pf):
            x, y = 0.0, 142.62232  # TODO: was in the loop, but that defeats its purpose
            direction = (-1)**j
            for i in range(num_pf_sections):
                pf_section = create_section(f'pf_{j}_{i}', self, length_of_sections, 0.15, start=(x+length_of_sections*direction*i, y), end=(x+length_of_sections*direction*(i+1), y))
                add_channels(pf_section, ('Leak', 'GRC_NA', 'Kv3_4', 'GRC_CA', ca_ion_accum), params["pf"], GrC_rev_potentials)
                pf_section.connect(pf[-1] if i > 0 else self.HD_aa[-1], 1, 0)
                pf.append(pf_section)

        # Voltage vector
        self.vm_soma = h.Vector()
        self.vm_soma.record(self.soma[0](0.5)._ref_v)

    def createsyn(self, nsyn_MF_AMPA, nsyn_MF_NMDA, list_dend_AMPA, list_dend_NMDA):
        from Synapse import Synapse

        self.MF_GrC_AMPA = []
        self.MF_GrC_NMDA_B = []

        # Mossy AMPA
        for x in range(nsyn_MF_AMPA):
            for z1 in list_dend_AMPA:
                self.MF_GrC_AMPA.append(Synapse('MF_AMPA', self, self.dend[z1]))

        # Mossy NMDA
        for y in range(nsyn_MF_NMDA):
            for z2 in list_dend_NMDA:
                self.MF_GrC_NMDA_B.append(Synapse('MF_NMDA_B', self, self.dend[z2]))
