#Granule cell model 2020 - Regular, non adapting firing.

#Authors: Stefano Masoli* 1, Marialuisa Tognolina* 1, Umberto Laforenza 2, Francesco Moccia 3, Egidio D'Angelo 1,4
#Author information: 1 Department of Brain and Behavioral Sciences, University of Pavia, Via Forlanini 6, I-27100, Pavia, Italy, 
#2 Department of Molecular Medicine, University of Pavia, Via Forlanini 6, I-27100, Pavia, Italy, 
#3 Department of Biology and Biotechnology, University of Pavia, Via Forlanini 6, I-27100, Pavia, Italy, 
#4 Brain Connectivity Center, IRCCS Mondino Foundation, Via Mondino 2, I-27100, Pavia, Italy, 
#* Co-Author

 #Citation: Masoli S.*, Tognolina M.*, Laforenza U., Moccia F., D’Angelo E. Parameter tuning differentiates granule cell subtypes enriching transmission properties at the cerebellum input stage. Nature communication biology 2020.

#DOI: 10.1038/s42003-020-0953-x


from neuron import h
import math
from Syntype_mild import Synapse_py3
import numpy as np


Grc_params = {
    "regular": {
        "soma_gmax_Leak": 0.00029038073716,
        "soma_gkbar_Kv3_4": 0.00076192450951999995,
    },
    "mild": {
        "soma_gmax_Leak": 0.00020821612897999999,
        "soma_gkbar_Kv3_4": 0.00053837153610999998,
    },
    "adapting": {
        "soma_gmax_Leak": 0.00027672909671000001,
        "soma_gkbar_Kv3_4": 0.00373151328841,
    }
}
Grc_params["accelerate"] = Grc_params["regular"].copy()
#Grc_params["accelerate"][...] = ...


class Grc_regular():
    def __repr__(self):
        return 'Grc_regular_morph[{}]'.format(self._id)
    def __init__(self, _id, subtype):
        self._id = _id
        
        h.load_file('stdlib.hoc')
        h.load_file('import3d.hoc')
        
        cell = h.Import3d_Neurolucida3()
        cell.input('morphology/GrC2020.asc')
            
        params = Grc_params[subtype]

        i3d = h.Import3d_GUI(cell,0)
        i3d.instantiate(self)
        
#Soma channels
        self.soma[0].nseg = 1 + (2 * int(self.soma[0].L / 40))
        self.soma[0].Ra = 100
        self.soma[0].cm = 2
        
        self.soma[0].insert('Leak')
        self.soma[0].gmax_Leak = params["soma_gmax_Leak"]
        
        self.soma[0].e_Leak = -60
        
        self.soma[0].insert('Kv3_4')
        self.soma[0].gkbar_Kv3_4 = params["soma_gkbar_Kv3_4"]
        
        self.soma[0].insert('Kv4_3')
        if subtype == 1:
            "gkbar_Kv4_3": 0.0028149683906099998,
        elif subtype == 2:
            "gkbar_Kv4_3": 0.0032501728450999999,
        elif subtype == 3:
            "gkbar_Kv3_4": 0.0027313162972600002,
        elif subtype == 4:
            "gkbar_Kv3_4": 0.0028149683906099998,
        self.soma[0].ek = -88
        
        self.soma[0].insert('Kir2_3')
        if subtype == 1:
            "gkbar_Kir2_3": 0.00074725514701999996,
        elif subtype == 2:
            "gkbar_Kir2_3": 0.00080747403035999997,
        elif subtype == 3:
            "gkbar_Kir2_3": 0.00094360184424999995,
        elif subtype == 4:
            "gkbar_Kir2_3": 0.00074725514701999996,
        
    
	
        self.soma[0].insert('GRC_CA') 
        if subtype == 1:
            "gcabar_GRC_CA": 0.00060938071783999998,
        elif subtype == 2:
            "gcabar_GRC_CA": 0.00066384354030999998,
        elif subtype == 3:
            "gcabar_GRC_CA": 0.00029165028328999998,
        elif subtype == 4:
            "gcabar_GRC_CA": 0.00060938071783999998,
	
        self.soma[0].insert('Kv1_1')
        if subtype == 1:
            "gbar_Kv1_1": 0.0056973826455499997,
        elif subtype == 2:
            "gbar_Kv1_1": 0.0046520692281700003,
        elif subtype == 3:
            "gbar_Kv1_1": 0.0031675812802999998,
        elif subtype == 4:
            "gbar_Kv1_1": 0.0056973826455499997,
        
        self.soma[0].insert('Kv1_5') 
        if subtype == 1:
            "gKur_Kv1_5": 0.00083407556713999999,
        elif subtype == 2:
            "gKur_Kv1_5": 0.00106988075956,
        elif subtype == 3:
            "gKur_Kv1_5": 0.00107176612352,
        elif subtype == 4:
            "gKur_Kv1_5": 0.00083407556713999999,
        
        
        self.soma[0].insert('Kv2_2_0010')
        if subtype == 1:
            "gKv2_2bar_Kv2_2_0010": 1.203410852e-05,
        elif subtype == 2:
            "gKv2_2bar_Kv2_2_0010": 2.5949576899999998e-05,
        elif subtype == 3:
            "gKv2_2bar_Kv2_2_0010": 6.710092624e-05,
        elif subtype == 4:
            "gKv2_2bar_Kv2_2_0010": 1.203410852e-05,
        

        if subtype == "accerlate":
            self.axon.insert('cdp5_CR_CAM')
        else:
            self.soma[0].insert('cdp5_CR')

        self.soma[0].push()
        self.soma[0].eca = 137.5
        h.pop_section()

        self.whatami = "GrC_2020"
        if subtype != "regular":
            self.whatami += "_" + subtype

#DEND		  
        for i in self.dend:
            i.nseg = 1 + (2 * int(i.L / 40))
            i.Ra = 100 
            i.cm = 2.5
                
            i.insert('Leak')
            if subtype == 1:
                i.gmax_Leak = 0.00025029700736999997
            elif subtype == 2:
                i.gmax_Leak = 0.00020424219215
            elif subtype == 3:
                i.gmax_Leak = 0.00029871180381000001
            elif subtype == 4:
                i.gmax_Leak = 0.00025029700736999997
            i.e_Leak =  -60	
            
            i.insert('GRC_CA')
            if subtype == 1:
                i.gcabar_GRC_CA = 0.0050012800845900002
            elif subtype == 2:
                i.gcabar_GRC_CA = 0.01841833779253
            elif subtype == 3:
                i.gcabar_GRC_CA = 0.024687091736070001
            elif subtype == 4:
                i.gcabar_GRC_CA = 0.0050012800845900002
                
            i.insert('Kca1_1')
            if subtype == 1:
                i.gbar_Kca1_1 = 0.010018074546510001
            elif subtype == 2:
                i.gbar_Kca1_1 = 0.02998872868395
            elif subtype == 3:
                i.gbar_Kca1_1 = 0.01185742892862
            elif subtype == 4:
                i.gbar_Kca1_1 = 0.010018074546510001
            i.ek = -88
        
            i.insert('Kv1_1') 
            if subtype == 1:
                i.gbar_Kv1_1 = 0.00381819207934
            elif subtype == 2:
                i.gbar_Kv1_1 = 0.00010675447184
            elif subtype == 3:
                i.gbar_Kv1_1 = 0.00015853886699000001
            elif subtype == 4:
                i.gbar_Kv1_1 = 0.00381819207934
            
            

            i.insert('cdp5_CR')
            
            i.push()
            i.eca = 137.5
            h.pop_section()

#Hilock  
        self.axon = h.Section(name = 'hilock', cell=self) 
        self.axon.L = 1
        self.axon.nseg = 1
        self.axon.diam = 1.5
        self.axon.Ra = 100
        self.axon.cm = 2
        
        self.axon.insert('Leak')
        if subtype == 1:
                self.axon.gmax_Leak = 0.00036958189720000001
        elif subtype == 2:
                self.axon.gmax_Leak = 0.00025295417368000002
        elif subtype == 3:
                self.axon.gmax_Leak = 0.00031475453130000002
        elif subtype == 4:
                self.axon.gmax_Leak = 0.00036958189720000001
        self.axon.e_Leak =  -60
        
        self.axon.insert('GRC_NA_FHF')
        if subtype == 1:
                self.axon.gnabar_GRC_NA_FHF = 0.0092880585146199995
        elif subtype == 2:
                self.axon.gnabar_GRC_NA_FHF = 0.011082499796400001
        elif subtype == 3:
                self.axon.gnabar_GRC_NA_FHF = 0.020910983616370001
        elif subtype == 4:
                self.axon.gnabar_GRC_NA_FHF = 0.0092880585146199995
        self.axon.ena = 87.39

        self.axon.insert('Kv3_4')
        if subtype == 1:
                self.axon.gkbar_Kv3_4 = 0.020373463109149999
        elif subtype == 2:
                self.axon.gkbar_Kv3_4 = 0.050732563882920002
        elif subtype == 3:
                self.axon.gkbar_Kv3_4 = 0.03097630887484
        elif subtype == 4:
                self.axon.gkbar_Kv3_4 = 0.020373463109149999
        self.axon.ek = -88
	
        self.axon.insert('GRC_CA')
        if subtype == 1:
                self.axon.gcabar_GRC_CA = 0.00057726155447
        elif subtype == 2:
                self.axon.gcabar_GRC_CA = 0.00028797253573000002
        elif subtype == 3:
                self.axon.gcabar_GRC_CA = 0.00019803691988000001
        elif subtype == 4:
                self.axon.gcabar_GRC_CA = 0.00057726155447
	
        self.axon.insert('cdp5_CR')
        
        self.axon.push() 
        self.axon.eca = 137.5
        h.pt3dadd(0.0, 5.62232, 0.0, self.axon.diam)
        h.pt3dadd(0.0, 6.62232, 0.0, self.axon.diam)
        h.pop_section()
	
        self.axon.connect(self.soma[0],0,0)  

#AIS
        self.ais=h.Section(name = 'ais', cell=self)
        self.ais.L = 10
        self.ais.nseg = 1
        self.ais.diam = 0.7
        self.ais.Ra = 100
        self.ais.cm = 1
        
        self.ais.insert('GRC_NA_FHF')
        if subtype == 1:
                self.ais.gnabar_GRC_NA_FHF = 1.28725006737226
        elif subtype == 2:
                self.ais.gnabar_GRC_NA_FHF = 1.28725006737226
        elif subtype == 3:
                self.ais.gnabar_GRC_NA_FHF = 1.5810107836409499
        elif subtype == 4:
                self.ais.gnabar_GRC_NA_FHF = 1.28725006737226
        self.ais.ena = 87.39

        self.ais.insert('Kv3_4')
        if subtype == 1:
                self.ais.gkbar_Kv3_4 = 0.0064959534065400001
        elif subtype == 2:
                self.ais.gkbar_Kv3_4 = 0.034592458064240002
        elif subtype == 3:
                self.ais.gkbar_Kv3_4 = 0.039582385081389997
        elif subtype == 4:
                self.ais.gkbar_Kv3_4 = 0.0064959534065400001
        self.ais.ek = -88
            
        self.ais.insert('Leak')
        if subtype == 1:
                self.ais.gmax_Leak = 0.00029276697557000002
        elif subtype == 2:
                self.ais.gmax_Leak = 0.00025011065810000001
        elif subtype == 3:
                self.ais.gmax_Leak = 0.00025512657995000002
        elif subtype == 4:
                self.ais.gmax_Leak = 0.00029276697557000002
        self.ais.e_Leak =  -60
	

        self.ais.insert('GRC_CA')
        if subtype == 1:
                self.ais.gcabar_GRC_CA = 0.00031198539471999999
        elif subtype == 2:
                self.ais.gcabar_GRC_CA = 0.00011630629281
        elif subtype == 3:
                self.ais.gcabar_GRC_CA = 0.00038160760886000002
        elif subtype == 4:
                self.ais.gcabar_GRC_CA = 0.00031198539471999999
	
        self.ais.insert('GRC_KM') 
        if subtype == 1:
                self.ais.gkbar_GRC_KM = 0.00056671971737000002
        elif subtype == 2:
                self.ais.gkbar_GRC_KM = 0.00044764153078999998
        elif subtype == 3:
                self.ais.gkbar_GRC_KM = 0.00049717923887
        elif subtype == 4:
                self.ais.gkbar_GRC_KM = 0.00056671971737000002
        
        self.ais.insert('cdp5_CR')

        
        self.ais.push()
        self.ais.eca = 137.5
		
        h.pt3dadd(0.0, 6.62232, 0.0, self.ais.diam)
        h.pt3dadd(0.0, 16.62232, 0.0, self.ais.diam)
        h.pop_section()
        
        lensec = 7
        secnumber_aa = int(126/lensec)
        secnumber_pf = int(1000/lensec)

        self.ais.connect(self.axon,1,0)

        self.HD_aa = [h.Section(cell=self, name='aa_'+str(x)) for x in range(secnumber_aa)]
        for b in self.HD_aa:
            b.L = lensec
            b.nseg = 1
            b.diam = 0.3
            b.Ra = 100
            b.cm = 1
            
            b.insert('GRC_NA')
            if subtype == 1:
                b.gnabar_GRC_NA = 0.026301636815019999
            elif subtype == 2:
                b.gnabar_GRC_NA = 0.026301636815019999
            elif subtype == 3:
                b.gnabar_GRC_NA = 0.025441894508310001
            elif subtype == 4:
                b.gnabar_GRC_NA = 0.026301636815019999
            b.ena = 87.39

            b.insert('Kv3_4')
            if subtype == 1:
                b.gkbar_Kv3_4 = 0.00237386061632
            elif subtype == 2:
                b.gkbar_Kv3_4 = 0.0046029972380800003
            elif subtype == 3:
                b.gkbar_Kv3_4 = 0.0046504514953399998
            elif subtype == 4:
                b.gkbar_Kv3_4 = 0.00237386061632
            b.ek = -88
                
            b.insert('Leak')
            if subtype == 1:
                b.gmax_Leak = 9.3640921249999996e-05
            elif subtype == 2:
                b.gmax_Leak = 7.8963697590000003e-05
            elif subtype == 3:
                b.gmax_Leak = 5.3037170669999997e-05
            elif subtype == 4:
                b.gmax_Leak = 9.3640921249999996e-05
            b.e_Leak =  -60
            
            b.insert('GRC_CA')
            if subtype == 1:
                b.gcabar_GRC_CA = 0.00068197420273000001
            elif subtype == 2:
                b.gcabar_GRC_CA = 0.00059214434259999998
            elif subtype == 3:
                b.gcabar_GRC_CA = 0.00031374692347000001
            elif subtype == 4:
                b.gcabar_GRC_CA = 0.00068197420273000001
            
            b.insert('cdp5_CR')
    
            b.push()
            b.eca = 137.5
            
            len_initial = 16.62232
            len_ending = 7
            
            h.pt3dadd(0.0, len_initial , 0.0, b.diam)
            h.pt3dadd(0.0, len_initial + len_ending, 0.0, b.diam)
            h.pop_section()
            
            len_initial = len_initial + len_ending

        self.HD_pf1 = [h.Section(cell=self, name='pf_'+str(x)) for x in range(secnumber_pf)]
        
        for i in self.HD_pf1:
            i.L = lensec
            i.nseg = 1
            i.diam = 0.15
            i.Ra = 100
            i.cm = 1
            
            i.insert('GRC_NA')
            if subtype == 1:
                i.gnabar_GRC_NA = 0.017718484492610001
            elif subtype == 2:
                i.gnabar_GRC_NA = 0.01896618618573
            elif subtype == 3:
                i.gnabar_GRC_NA = 0.0142518259615
            elif subtype == 4:
                i.gnabar_GRC_NA = 0.017718484492610001
            i.ena = 87.39

            i.insert('Kv3_4')
            if subtype == 1:
                i.gkbar_Kv3_4 = 0.0081756804703699993
            elif subtype == 2:
                i.gkbar_Kv3_4 = 0.0094015060525799998
            elif subtype == 3:
                i.gkbar_Kv3_4 = 0.0098649550733799999
            elif subtype == 4:
                i.gkbar_Kv3_4 = 0.0081756804703699993
            i.ek = -88
                
            i.insert('Leak')
            if subtype == 1:
                i.gmax_Leak = 3.5301616000000001e-07
            elif subtype == 2:
                i.gmax_Leak = 4.1272473000000001e-07
            elif subtype == 3:
                i.gmax_Leak = 1.4118927999999999e-07
            elif subtype == 4:
                i.gmax_Leak = 3.5301616000000001e-07
            i.e_Leak =  -60
            
            i.insert('GRC_CA') 
            if subtype == 1:
                i.gcabar_GRC_CA = 0.00020856833529999999
            elif subtype == 2:
                i.gcabar_GRC_CA = 0.00064742320254000001
            elif subtype == 3:
                i.gcabar_GRC_CA = 0.00024821458382999999
            elif subtype == 4:
                i.gcabar_GRC_CA = 0.00020856833529999999
            
            i.insert('cdp5_CR')

            i.push()
            i.eca = 137.5
            
            len_initial = 142.62232
            len_ending = 7
            
            h.pt3dadd(len_initial, len_initial , 0.0, i.diam)
            h.pt3dadd(len_initial + len_ending, len_initial , 0.0, i.diam)
            h.pop_section()
            
            len_initial = len_initial + len_ending
            
        self.HD_pf2 = [h.Section(cell=self, name='pf_'+str(x)) for x in range(secnumber_pf)]	    
        for z in self.HD_pf2:  	
            z.L = lensec
            z.nseg = 1
            z.diam = 0.15
            z.Ra = 100
            z.cm = 1
            
            z.insert('GRC_NA')
            if subtype == 1:
                z.gnabar_GRC_NA = 0.017718484492610001
            elif subtype == 2:
                z.gnabar_GRC_NA = 0.01896618618573
            elif subtype == 3:
                z.gnabar_GRC_NA = 0.0142518259615
            elif subtype == 4:
                z.gnabar_GRC_NA = 0.017718484492610001
            z.ena = 87.39

            z.insert('Kv3_4')
            if subtype == 1:
                z.gkbar_Kv3_4 = 0.0081756804703699993
            elif subtype == 2:
                z.gkbar_Kv3_4 = 0.0094015060525799998
            elif subtype == 3:
                z.gkbar_Kv3_4 = 0.0098649550733799999
            elif subtype == 4:
                z.gkbar_Kv3_4 = 0.0081756804703699993
            z.ek = -88
                
            z.insert('Leak')
            if subtype == 1:
                z.gmax_Leak = 3.5301616000000001e-07
            elif subtype == 2:
                z.gmax_Leak = 4.1272473000000001e-07
            elif subtype == 3:
                z.gmax_Leak = 1.4118927999999999e-07
            elif subtype == 4:
                z.gmax_Leak = 1.4118927999999999e-07
            z.e_Leak =  -60
            
            z.insert('GRC_CA')
            if subtype == 1:
                z.gcabar_GRC_CA = 0.00020856833529999999
            elif subtype == 2:
                z.gcabar_GRC_CA = 0.00064742320254000001
            elif subtype == 3:
                z.gcabar_GRC_CA = 0.00024821458382999999
            elif subtype == 4:
                z.gcabar_GRC_CA = 0.00020856833529999999
            
            z.insert('cdp5_CR')
        
            z.push()
            z.eca = 137.5
            
            len_initial = 142.62232
            len_ending = 7
            
            h.pt3dadd(len_initial, len_initial , 0.0, i.diam)
            h.pt3dadd(len_initial - len_ending, len_initial , 0.0, i.diam)
            h.pop_section()
            
            len_initial = len_initial - len_ending
	  
#Connections
      
#AA
        for j in range(secnumber_aa-1):
            l = j+1
            self.HD_aa[l].connect(self.HD_aa[j],1,0)   
#PF 
        for i in range(secnumber_pf-1):
            l = i+1
            self.HD_pf1[l].connect(self.HD_pf1[i],1,0) 
            self.HD_pf2[l].connect(self.HD_pf2[i],1,0) 
	
        self.HD_pf1[0].connect(self.HD_aa[secnumber_aa-1],1,0) 
        self.HD_pf2[0].connect(self.HD_aa[secnumber_aa-1],1,0) 

#Axon connection to the AIS        
        self.HD_aa[0].connect(self.ais,1,0)

#Time and Voltage vectors        
        self.time_vector = h.Vector()
        self.time_vector.record(h._ref_t)

        self.vm_soma = h.Vector()
        self.vm_soma.record(self.soma[0](0.5)._ref_v)

#SYNAPSES
    def createsyn(self, nsyn_MF_AMPA, nsyn_MF_NMDA, list_dend_AMPA, list_dend_NMDA):

        self.MF_GrC = []
        self.MF_GrC_mossy = []
      
        #Mossy AMPA
        for x in range(0,nsyn_MF_AMPA):	
            for z1 in list_dend_AMPA:
                self.MF_GrC.append(Synapse_py3('mossy',self,self.dend[z1]))    

        #Mossy NMDA
        for y in range(0,nsyn_MF_NMDA):	
            for z2 in list_dend_NMDA:
                self.MF_GrC_mossy.append(Synapse_py3('mossynmda',self,self.dend[z2])) 
