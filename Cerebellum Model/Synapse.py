from neuron import h
import Golgi
import GrC
from utils import set_attrs

class Synapse:
    def __init__(self, source, target, section, weight=1):
        self.source = source  # can be a string or an object, although right now it is never an object
        self.target = target
        self.target_section = section
        self.weight = weight

        self.input = h.NetStim(0.5)
        self.input.start = -10
        self.input.number = 1
        self.input.interval = 1e9

        self.postsyns = {}

        if source == 'PF_AMPA':
            if isinstance(target, Golgi.Golgi):
                # Make a parallel fiber synapse onto a Golgi cell
                # Use deterministic synapses
                self.whatami = "syn_PF2GoC_det"
                self.postsyns['AMPA'] = [set_attrs(h.Golgi_PF_syn(0.5, sec=section), tau_facil=10.8*5, tau_rec=35.1, tau_1=30, gmax=1200, U=0.4)] # TODO: Incorporate correct parameters

        if source == 'PF_NMDA':
            if isinstance(target, Golgi.Golgi):
                # Make a parallel fiber synapse onto a Golgi cell
                # Use deterministic synapses
                self.whatami = "syn_PF2GoC_det"
                self.postsyns['NMDA'] = [set_attrs(h.Golgi_PF_syn(0.5, sec=section), tau_facil=10.8*5, tau_rec=35.1, tau_1=30, gmax=1200, U=0.4)]

        elif source == 'MF_AMPA':
            if isinstance(target, Golgi.Golgi):
                # Make a mossy fiber synapse onto a Golgi cell
                # Use deterministic synapses
                self.whatami = "syn_MF2GoC_det"
                self.postsyns['AMPA'] = [set_attrs(h.Golgi_MF_syn(0.5, sec=section), tau_facil=8, tau_rec=5, tau_1=1, gmax=1200, U=0.43)]
            elif isinstance(target, GrC.GrC):
                self.whatami = "syn_MF2GrC_det"
                self.postsyns['AMPA'] = [set_attrs(h.GRANULE_Ampa_det_vi(0.9, sec=section), tau_facil=5, tau_rec=8, tau_1=1, gmax=1200, U=0.43)]

        elif source == 'MF_NMDA_B':
            if isinstance(target, Golgi.Golgi):
                # Make a mossy fiber NMDAB onto a Golgi cell
                # Use deterministic synapses*
                self.whatami = "syn_MFB2GoC_det"
                self.postsyns['NMDA'] = [set_attrs(h.PC_NMDA_NR2B(0.5, sec=section), tau_facil=5, tau_rec=8, tau_1=1, gmax=10000, U=0.43)]
            elif isinstance(target, GrC.GrC):
                self.whatami = "syn_MFB2GrC_det"
                self.postsyns['NMDA'] = [set_attrs(h.GRANULE_Nmda_det_vi(0.9, sec=section), tau_facil=5, tau_rec=8, tau_1=1, gmax=18800, U=0.43)]

        elif source == 'AA_AMPA':
            if isinstance(target, Golgi.Golgi):
                # Make a AA synapse onto a Golgi cell
                # Use deterministic synapses*
                self.whatami = "syn_AA2GoC_det"
                self.postsyns['AMPA'] = [set_attrs(h.Golgi_PF_syn(0.7, sec=section), tau_facil=54, tau_rec=35.1, tau_1=30, gmax=1200, U=0.4)]

        if len(self.postsyns) == 0:
            print('Bad Synapse!')
            print(source, '=>', target)
        else:
            self.nc_syn = [h.NetCon(self.input, receptor[0], 0, 0.1, 1) for receptor in self.postsyns.values()]
