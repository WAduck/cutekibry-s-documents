#!/usr/bin/python3
from cyaron import *
from os import system
from random import shuffle
import math

def log(n):
    return int(math.log(n))

def sqrt(n):
    return int(math.sqrt(n))

system('g++ -o chocolate chocolate.cpp -DSTDIO')

_p = [-1] + [100]*6 + [1000]*6 + [10000]*8
_n = [-1] + [10]*6 + [1000]*6 + [100000]*8

for i in range(20, 21):
    data = IO(file_prefix='chocolate', data_id=i)

    m = randint(_n[i]-sqrt(i), _n[i])
    if i & 1:
        n1 = m // 3 + randint(-sqrt(m // 3), log(m // 3))
        n2 = m // 3 + randint(-sqrt(m // 3), log(m // 3))
        a = [randint(1, 3) for j in range(m)]
    else:
        n1 = m // 2 + randint(-sqrt(m // 2), log(m // 2))
        n2 = m // 2 + randint(-sqrt(m // 2), log(m // 2))
        a = [randint(1, 2) for j in range(m)]
    n2 = min(n2, m - n2)
    m1 = sum([x == 1 for x in a])
    m2 = sum([x == 2 for x in a])
    m3 = sum([x == 3 for x in a])
    a = []
    while m2 + m3 - max(0, n1 - m1) < n2:
        if randint(0, 1):
            n2 -= 1
        else:
            n1 -= 1
    a = [1]*m1 + [2]*m2 + [3]*m3
    shuffle(a)

    data.input_writeln(m, n1, n2)
    for t in a:
        data.input_writeln(t, randint(1, _p[i]))
    data.output_gen('./chocolate')
    data.close()
