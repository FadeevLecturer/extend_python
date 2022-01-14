import sys

import os
import ctypes
import argparse


def parse_args():
    default_path = os.path.join("..", "libshared", "libshared.so")
    
    parser = argparse.ArgumentParser(description='Adds two integers.')
    parser.add_argument('terms',  type=int, nargs='+', help='Two terms to sum')
    parser.add_argument('--dll', default=default_path)
    
    args = parser.parse_args()
    assert len(args.terms) == 2, "takes exactly two parameters" 
    return args



args = parse_args()
path_to_dll = args.dll
a, b = args.terms

dll = ctypes.cdll.LoadLibrary(path_to_dll)
dll.add.argtypes = (ctypes.c_int, ctypes.c_int)
dll.add.restype = ctypes.c_int



c1 = dll.add(a, b)
c2 = a + b
print(f"C++:\t{c1}")
print(f"python:\t{c2}")
