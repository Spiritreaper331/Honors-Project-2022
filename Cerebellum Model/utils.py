
from neuron import h

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
