import argparse

import numpy as np

import mylib 


def parse_args():
    parser = argparse.ArgumentParser(description='Sums a random numpy array.')
    parser.add_argument('shape',  type=int, nargs='+', help='Two terms to sum')
    args = parser.parse_args()
    return args

args = parse_args()

array = np.random.randn(*args.shape)
array = array.astype(np.float64)
print(array)


s1 = mylib.sum(array)
s2 = array.sum()
print(f"C++:\t{s1}")
print(f"numpy:\t{s2}")