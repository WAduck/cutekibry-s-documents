#!/usr/bin/python3
from random import *
from os import system

MAXM = 10000
AI = 100000000
k = 30
system('g++ -o 2302 2302.cpp -g && g++ -o brust brust.cpp -g')
times = 0


while 1:
    times += 1
    with open('2302.in', 'w') as data:
        m = randint(MAXM>>1, MAXM)
        x = 0
        data.write('{} 0 0 0\n'.format(m))
        for i in range(m):
            opt = randint(1, 2)
            if opt == 1:
                a = randint(-AI, AI)
                b = randint(0, MAXM*k)
                while x + (a << b) < 0:
                    a = randint(-AI, AI)
                    b = randint(0, MAXM*k)
                x += a << b
                data.write('{} {} {}\n'.format(opt, a, b))
            else:
                a = randint(0, MAXM*k)
                data.write('{} {}\n'.format(opt, a))
    # exit(0)
    if system('./2302 && ./brust') > 0:
        print('Runtime Error...')
        exit(0)
    if system('diff 2302.out brust.out') > 0:
        print('Uncorrect!!!')
        exit(0)
    else:
        print('{} correct'.format(times))
