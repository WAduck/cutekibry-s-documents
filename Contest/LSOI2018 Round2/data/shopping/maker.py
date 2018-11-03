#!/usr/bin/python3
from cyaron import *
from os import system
import math

system('g++ -o shopping shopping.cpp -DSTDIO')

def log(x):
    return int(math.log(x, 2))

_n = [-1] + [10]*6 + [100]*4

for i in range(9, 10):
    print('Processing', i)
    data = IO(file_prefix='shopping', data_id=i)
    n = randint(_n[i]-log(_n[i]), _n[i])
    a = randint(90, 100)
    b = randint(9900, 10000)
    data.input_writeln(n, a, b)
    data.input_writeln([randint(1, 100000) for j in range(n-1)])
    for j in range(n):
        m = randint(1, 3)
        x = []
        for k in range(m):
            x.append(randint(1, 40))
            x.append(randint(1, 1000))
        data.input_writeln(m, x)
    data.output_gen('./shopping')
    data.close()
