#!/usr/bin/python3
from cyaron import *
import os

_n = [-1, 1, 6, 10, 14, 19, 83, 178, 251, 317, 391]

os.system('g++ -DSTDIO -o magic magic.cpp')

for i in range(1, 11):
    data = IO(file_prefix='magic', data_id=i)
    data.input_writeln(_n[i])
    data.output_gen('./magic')
