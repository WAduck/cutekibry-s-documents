#!/usr/bin/python3
from pathlib import *
import os

with open('autorun.py', 'r', encoding='utf-8') as f:
    exec(''.join(f.readlines()))

SPLIT = '-'*64

def strwidth(s):
    res = 0
    for ch in s:
        if ord(ch) < 128:
            res += 1
        else:
            res += 2
    return res

def diffrank(s):
    if s == '入门难度':
        return 0
    elif s == '普及-':
        return 1
    elif s == '普及/提高-':
        return 2
    elif s == '普及+/提高':
        return 3
    elif s == '提高+/省选-':
        return 4
    elif s == '省选/NOI-':
        return 5
    elif s == 'NOI/NOI+/CTSC':
        return 6
    else:
        return -1

try:
    import colorama
    colorama.init(autoreset=True)
    def raise_warning(message):
        print(colorama.Fore.YELLOW + 'Warning: ' + message)
    def raise_error(message):
        print(colorama.Fore.RED + 'Error: ' + message)
    diff_color = {
        'bright': colorama.Style.BRIGHT,
        'reset': colorama.Back.RESET + colorama.Style.NORMAL,
        '入门难度': colorama.Back.RED,
        '普及-': colorama.Back.YELLOW,
        '普及/提高-': colorama.Back.LIGHTYELLOW_EX,
        '普及+/提高': colorama.Back.GREEN,
        '提高+/省选-': colorama.Back.LIGHTBLUE_EX,
        '省选/NOI-': colorama.Back.MAGENTA,
        'NOI/NOI+/CTSC': colorama.Back.BLUE,
    }
except ModuleNotFoundError:
    diff_color = dict()
    def raise_warning(message):
        print('Warning: ' + message)

try:
    from functools import cmp_to_key
except ModuleNotFoundError:
    def cmp_to_key(mycmp): # Copy from https://docs.python.org/3.3/howto/sorting.html
        """Convert a cmp= function into a key= function"""
        class K(object):
            __slots__ = ['obj']
            def __init__(self, obj):
                self.obj = obj
            def __lt__(self, other):
                return mycmp(self.obj, other.obj) < 0
            def __gt__(self, other):
                return mycmp(self.obj, other.obj) > 0
            def __eq__(self, other):
                return mycmp(self.obj, other.obj) == 0
            def __le__(self, other):
                return mycmp(self.obj, other.obj) <= 0
            def __ge__(self, other):
                return mycmp(self.obj, other.obj) >= 0
            def __ne__(self, other):
                return mycmp(self.obj, other.obj) != 0
            __hash__ = None
        return K

try:
    file = open('list.txt')
    problem_list = eval(''.join(file.readlines()))
    print('Read and execute \'list.txt\' successfully.')

except FileNotFoundError:
    raise RuntimeError('\'list.txt\' does not exist, please generate it through \'list-gen.py\'')

def showhelp():
    print('Welcome to query system!')
    print('You can query or sort the problems through input python3 functions.')
    print('Available variables:')
    print('\t- {:30}{:30}{:30}'.format('Name', 'Type', 'Description'))
    print('\t- {:30}{:30}{:30}'.format('id', str(type(str())), 'Id of the problem (including OJ\'s name)'))
    print('\t- {:30}{:30}{:30}'.format('name', str(type(str())), 'Name of the problem'))
    print('\t- {:30}{:30}{:30}'.format('diff', str(type(list())), 'Difficulty of the problem'))
    print('\t- {:30}{:30}{:30}'.format('tag', str(type(str())), 'List of tags of the problem'))

    print(SPLIT)
    print('Query')
    print(SPLIT)
    print('To query problems, please input \'query\', then input a python3 function which returns a bool value.')
    print('Examples:')
    print('\t- {:40}{:40}'.format('name == \'LGOJ P1073 最优贸易\'', 'Query problems with name == \'LGOJ P1073 最优贸易\''))
    print('\t- {:40}{:40}'.format('diff == \'提高+/省选-\'', 'Query problems with difficulty == \'提高+/省选-\''))
    print('\t- {:40}{:40}'.format('find(name, \'LGOJ P1073 最优贸易\') == -1', 'Query problems without substring \'LGOJ P1073 最优贸易\' in name'))
    print('\t- {:41}{:40}'.format('tag.count(\'最短路\')', 'Query problems with tag \'最短路\''))
    print()

    print(SPLIT)
    print('Sort')
    print(SPLIT)
    print('To sort the problem list, please input \'sort\', then input a python3 function which returns a bool value.')
    print('Examples:')
    print('\t- {:40}{:40}'.format('-1 if id1 < id2 else 1', 'Sort the problem list by id (ascending)'))
    print('\t- {:40}{:40}'.format('-1 if len(tag1) > len(tag2) else 1', 'Sort the problem list by the length of tag list (descending)'))
    print()

    print(SPLIT)
    print('strwidth()')
    print(SPLIT)
    print('strwidth(s) will return the width of the string s.')
    print('Examples:')
    print('strwidth(\'153\')=3')
    print('strwidth(\'数字\')=4')
    print('strwidth(\'一二三12345\')=11')
    print()

    print(SPLIT)
    print('diffrank()')
    print(SPLIT)
    print('diffrank(s) will return the rank of the difficulty s.')
    print('0~6 for \'入门难度\'...\'NOI/NOI+/CTSC\', and -1 for others.')
    print('Examples:')
    print('strwidth(\'入门难度\')=0')
    print('strwidth(\'普及-\')=1')
    print('strwidth(\'普及+/提高\')=3')
    print()

    print(SPLIT)
    print('Options')
    print(SPLIT)
    print('\t- {:40}{:40}'.format('help', 'Show help'))
    print('\t- {:40}{:40}'.format('query', 'Query problems'))
    print('\t- {:40}{:40}'.format('sort', 'Sort the problem list'))
    print()

    print(SPLIT)
    print('Others')
    print(SPLIT)
    print('Warning: This system does not block codes like \'help()\' and some dangerous functions.')
    print('Please pay attention while using it.')
    print()

showhelp()

while True:
    try:
        read = input('>> ').strip()
        if read == 'exit':
            exit()
        elif read == 'query':
            read = input('Input function: ').strip()
            exec(
'''
def func(name, diff, tag):
    return {}
'''
.strip().format(read))
            problems = [problem for problem in problem_list if func(problem['name'], problem['diff'], problem['tag'])]
            print('Query successfully and return with {} result(s):'.format(len(problems)))
            problems.insert(0, {'name':'name', 'diff':'diff', 'tag':'tag', 'id':'id'})
            idlen = 0
            namelen = 0
            difflen = 0
            for problem in problems:
                idlen = max(idlen, strwidth(problem['id']))
                namelen = max(namelen, strwidth(problem['name']))
                difflen = max(difflen, strwidth(problem['diff']))
            for problem in problems:
                print('{i}{_is}{n}{ns}{dcol}{d}{clr}{ds}{t}'.format(
                    i=problem['id'],
                    _is=(idlen-strwidth(problem['id'])+2)*' ',
                    n=problem['name'],
                    ns=(namelen-strwidth(problem['name'])+2)*' ',
                    d=problem['diff'],
                    dcol=diff_color.get(problem['diff'], '')+diff_color.get('bright', ''),
                    ds=(difflen-strwidth(problem['diff'])+2)*' ',
                    clr=diff_color.get('reset', ''),
                    t=str(problem['tag']),
                    ))
            exec('del func')
        elif read == 'sort':
            read = input('Input function: ').strip()
            exec(
'''
def func(x, y):
    id1 = x['id']
    name1 = x['name']
    diff1 = x['diff']
    tag1 = x['tag']
    id2 = y['id']
    name2 = y['name']
    diff2 = y['diff']
    tag2 = y['tag']
    return {}
'''
.strip().format(read))
            problem_list = sorted(problem_list, key=cmp_to_key(func))
            exec('del func')
        elif read == 'help':
            showhelp()
        else:
            raise_error('Unknown command \'{}\''.format(read))
    except Exception as e:
        raise e
        # raise_error(str(e))
