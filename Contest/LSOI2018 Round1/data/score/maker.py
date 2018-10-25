#!/usr/bin/python3
from cyaron import *
import os


os.system('g++ -DSTDIO -o score score.cpp')

for i in range(7, 11):
    data = IO(file_prefix='score', data_id=i)
    n = randint(80000, 100000)
    m = randint(80000, 100000)
    data.input_writeln(n, m)
    data.input_writeln([randint(0, 100) for j in range(n)])
    data.input_writeln([randint(0, 100) for j in range(m)])
    data.input_write(randint(0, 100))
    data.output_gen('./score')
    data.close()
