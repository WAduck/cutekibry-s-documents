#!/usr/bin/python3
from cyaron import *
from os import system
from random import *
from math import log10

system('g++ -o librarian librarian.cpp -DSTDIO')

for i in range(1, 11):
    data = IO(file_prefix='librarian', data_id=i)
    n = randint(80, 100)
    m = randint(80, 100)
    data.input_writeln(n, m)
    s = []
    for j in range(n):
        if i <= 6:
            x = randint(1, 99999)
        else:
            x = randint(1, 1e100-1)
        s.append(x)
        data.input_writeln(x)
    for j in range(m):
        if randint(0, 1):
            if i <= 6:
                x = randint(1, 99999)
            else:
                x = randint(1, 1e100-1)
        else:
            x = s[randint(0, n-1)]
        data.input_writeln(int(log10(x)+1), x)
    data.output_gen('./librarian')
    data.close()
