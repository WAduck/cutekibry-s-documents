#!/usr/bin/python3
from cyaron import *
from math import log
import os

_n = [-1] + [100]*3 + [100000]*3 + [600000]*3 + [400000]
_a = [-1, [1, 20], [1, 100], [1, 1000], [1, 10000], [8000, 10000], [2, 5000], [1, 100000], [1, 600000], [500000, 600000], [400000, 600000]]
_b = [-1] + [20] + [100]*2 + [5000] + [10000] + [5000] + [600000]*4
os.system('g++ -DSTDIO -o chess chess.cpp')

for i in range(7, 10):
    print('Processing', i)
    data = IO(file_prefix='chess', data_id=i)
    n = randint(int(_n[i]-log(_n[i], 2)), _n[i])
    data.input_writeln(n)
    if i <= 3 or i >= 7:
        a = [randint(_a[i][0], _a[i][1]) for j in range(n)]
    else:
        m = randint(80, 100)
        x = [randint(_a[i][0], _a[i][1]) for j in range(m)]
        a = [x[randint(0, m-1)] for j in range(n)]
    data.input_writeln(a)
    m = randint(int(_n[i]-log(_n[i], 2)), _n[i])
    data.input_writeln(m)
    for j in range(m):
        data.input_writeln(randint(1, _b[i]))
    data.output_gen('./chess')
