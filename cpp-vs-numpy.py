import numpy as np
import random
import timeit
import pandas
from matplotlib import pyplot

from ql_std_cpp import stdev_cpp
from ql_package.ql_std_jit import stdev_nopy

# test stdev_cpp & stdev_nopy
if __name__ == '__main__':
    print(f"{__file__} started ...")
    x = [random.random() for _ in range(0, 5000)]
    stdev_nopy(x)   # compiling Py

    n_lens = range(5000, 30000, 2500)
    repeats = 10000 
    p_time = []
    c_time = []

    for ln in n_lens:
        rands = [random.random() for _ in range(0, ln)]
        p_time = np.append(p_time, timeit.timeit(lambda: stdev_nopy(rands), number=repeats))
        c_time = np.append(c_time, timeit.timeit(lambda: stdev_cpp(rands), number=repeats))
        
    data = np.array([np.transpose(p_time), np.transpose(c_time)])
    df = pandas.DataFrame(data.transpose(), index=n_lens, columns=['Numpy-jit', 'C++'])
    
    pyplot.figure()
    df.plot()
    pyplot.legend(loc='best')
    pyplot.ylabel('Time (Seconds)')
    pyplot.xlabel('Number of Elements')
    pyplot.title(f'Standard-deviation: {repeats} Runs')
    pyplot.savefig('new_big_array.png')
    
    print(f"{__file__} finished")
