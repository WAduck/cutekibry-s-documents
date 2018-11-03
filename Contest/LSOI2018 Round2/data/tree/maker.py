#!/usr/bin/python3
from cyaron import *
from os import system

def func(no):
    return chr(no) if no != 128 else '\n'

system('g++ -o tree tree.cpp -DSTDIO')

for i in range(4, 11):
    print('Processing', i)
    data = IO(file_prefix='tree', data_id=i)
    n = randint(80000, 90000)
    s = ''.join([func(randint(32, 128)) for j in range(n)])
    if i <= 6:
        s = s.replace('\n', chr(randint(33, 127))).replace(' ', chr(randint(33, 127)))
    for j in range(randint(1, 100)):
        p = randint(0, 70000)
        s = s.replace(s[p:p+7], 'freopen')
    data.input_writeln(s)
    data.output_gen('./tree')
    data.close()
