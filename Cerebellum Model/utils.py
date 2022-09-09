
from neuron import h
import h5py

def load_3d_morphology(cell, filename):
    """Loads a 3D Morphology using Neurolucida from an asc file into a cell object."""
    h.load_file('stdlib.hoc')
    h.load_file('import3d.hoc')
    morphology = h.Import3d_Neurolucida3()
    morphology.input(filename)
    i3d = h.Import3d_GUI(morphology, 0)
    i3d.instantiate(cell)


def add_channels(section, channels, params, rev_potentials):
    """
    Add the list of channels to the given section and set the given parameters
    and reversal potentials.
    """
    section.push()  # probably doesn't help, but also doesn't hurt
    for channel in channels:
        section.insert(channel)
    for name, value in params.items():
        setattr(section, name, value)
    for name, value in rev_potentials.items():
        if hasattr(section, name):  # can't set ena if no Na channels
            setattr(section, name, value)
    h.pop_section()


def create_section(name, cell, length, diam, nseg=1, Ra=100, cm=1, start=None, end=None):
    """
    Creates a section with the given name in the given cell. Sets the given
    parameters (with reasonable defaults for most things). Return the section.
    """
    section = h.Section(name=name, cell=cell)
    section.L = length
    section.nseg = nseg
    section.diam = diam
    section.Ra = Ra
    section.cm = cm
    if start is not None and end is not None:
        section.push()
        h.pt3dadd(*start, 0.0, diam)
        h.pt3dadd(*end, 0.0, diam)
        h.pop_section()
    return section

def set_attrs(object, **kwargs):
    """
    Sets all the key-value pairs from a dictionary as the attributes on the
    given object. Returns the objects.
    """
    for name, value in kwargs.items():
        setattr(object, name, value)
    return object


def export_data(sim_dict, model_name, file_name):
    """
    Exports data from sim_dict to hdf5 file. 
    :param sim_dict: dictionary of values from simulations
    :param model_name: string of model name for top_level hdf5 group
    :param file_name: string name of file to save to
    """
    with h5py.File(file_name, mode = 'a') as file:
        
        if model_name in file:
            del file[model_name]

        file.create_group(model_name)
        
        for category in sim_dict.keys():
            print(file[model_name])
            file[model_name].create_group(category)
            
            for model_value in sim_dict[category].keys():
                file[model_name][category].create_dataset(model_value, data = sim_dict[category][model_value])
                print(file[model_name][category][model_value])

                    
def import_data(file_name):
    """
    Imports data from hdf5 file
    :param file_name: string name of hdf5 file
    :return sim_dict: dictionary of values 
    """
    sim_dict = {}
    with h5py.File(file_name, 'r') as file:

        for model_name in file:
            sim_dict[model_name] = {}

            for category in file[model_name]:
                sim_dict[model_name][category] = {}
                    
                if(category == 'data' or category == 'analysis'):    
                    for model_value in file[model_name][category]:
                        sim_dict[model_name][category][model_value] = file[model_name][category][model_value][:]
                else:
                    for key, model_value in file[model_name][category].attrs.items():
                        sim_dict[model_name][category][key] = model_value

    return sim_dict
