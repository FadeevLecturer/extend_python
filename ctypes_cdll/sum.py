import sys
import os
import ctypes
import argparse

import numpy as np
np.set_printoptions(precision=2)

def parse_args():
    default_path = os.path.join("..", "libshared", "libshared.so")
    
    parser = argparse.ArgumentParser(description='Sums a random numpy array.')
    parser.add_argument('shape',  type=int, nargs='+', help='Two terms to sum')
    parser.add_argument('--dll', default=default_path)
    
    args = parser.parse_args()
    return args


args = parse_args()
path_to_dll = args.dll
shape = args.shape

dll = ctypes.cdll.LoadLibrary(path_to_dll)
double_pointer = ctypes.POINTER(ctypes.c_double)
dll.sum.argtypes = (double_pointer, ctypes.c_size_t)
dll.sum.restype = ctypes.c_double

array = np.random.randn(*shape)
array = array.astype(ctypes.c_double)
print(array)
pointer = array.ctypes.data_as(double_pointer)
nelem = array.size

s1 = dll.sum(pointer, array.size)
s2 = array.sum()
print(f"C++:\t{s1}")
print(f"numpy:\t{s2}")
