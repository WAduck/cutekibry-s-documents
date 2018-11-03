#!/usr/bin/python3
from cyaron import *
from os import system
import math

def log2(x):
    return int(math.log(x, 2))
def sqrt(x):
    return int(math.sqrt(x))

system('g++ -o cinnamoroll cinnamoroll.cpp -DSTDIO')

_n = [-1] + [20]*3 + [5000]*3 + [500000]*4 + [1e9]*10
_m = [-1] + [int(ch) for ch in '01201201120120121222']

for i in range(4, 21):
    print('Processing', i)
    data = IO(file_prefix='cinnamoroll', data_id=i)
    n = randint(_n[i]-sqrt(_n[i]), _n[i])
    m = _m[i]
    data.input_writeln(n, m)
    x = 1
    while n % x == 0:
        if i <= 18:
            x = randint(2, sqrt(n))
        else:
            x = randint(2, n)
    y = 1
    while n % y == 0 or x % y == 0 or y % x == 0:
        if i <= 18:
            y = randint(2, sqrt(n))
        else:
            y = randint(2, n)
    if m == 0:
        data.input_writeln()
    elif m == 1:
        data.input_writeln(x)
    else:
        data.input_writeln(x, y)
    data.output_gen('./cinnamoroll')
    data.close()
