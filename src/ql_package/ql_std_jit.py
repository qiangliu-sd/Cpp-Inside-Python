
import numpy as np
from numba import jit

@jit(nopython=True)
def stdev_nopy(arr):
    """jit-compiled numpy.std()"""
    return np.std(np.array(arr))
    #return np.std(arr)   # DONT work  ascontiguousarray