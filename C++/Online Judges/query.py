#!/usr/bin/python3
from pathlib import *
import os

with open('autorun.py', 'r', encoding='utf-8') as f:
    exec(''.join(f.readlines()))

SPLIT = '-'*80

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

def getoj(s):
    for pattern in ['BZOJ', 'LGOJ', 'USACO', 'SPOJ', 'POJ', 'LOJ']:
        if s.find(pattern) != -1:
            return pattern
    return 'UNKNOWN'

try:
    import colorama
    colorama.init(autoreset=True)
    def raise_warning(message):
        print(colorama.Fore.YELLOW + '警告：' + message)
    def raise_error(message):
        print(colorama.Fore.RED + '错误：' + message)
    color = {
        't-LGOJ': colorama.Fore.LIGHTBLUE_EX,
        't-USACO': colorama.Fore.LIGHTGREEN_EX,
        't-LOJ': colorama.Fore.BLACK + colorama.Back.WHITE,
        't-white': colorama.Fore.WHITE,
        'bright': colorama.Style.BRIGHT,
        'reset': colorama.Back.RESET + colorama.Fore.RESET + colorama.Style.NORMAL,
        'bg-入门难度': colorama.Back.RED,
        'bg-普及-': colorama.Back.YELLOW,
        'bg-普及/提高-': colorama.Back.LIGHTYELLOW_EX,
        'bg-普及+/提高': colorama.Back.GREEN,
        'bg-提高+/省选-': colorama.Back.LIGHTBLUE_EX,
        'bg-省选/NOI-': colorama.Back.MAGENTA,
        'bg-NOI/NOI+/CTSC': colorama.Back.BLUE,
    }
except ModuleNotFoundError:
    color = dict()
    def raise_warning(message):
        print('警告：' + message)
    def raise_error(message):
        print('错误：' + message)

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
    print('成功读取并处理 \'list.txt\' 。')

except FileNotFoundError:
    raise RuntimeError('\'list.txt\' 不存在，请运行 \'list-gen.py\' 或手动生成 \'list.txt\' 。')

def showhelp():
    print("""
--------------------------------
# 欢迎来到查询系统！
--------------------------------
你可以通过输入 python3 函数来查询或排序题目。
可用参数：
名字              类型                描述
id                <class 'str'>       题目编号（包括OJ名）
name              <class 'str'>       题目名字
diff              <class 'str'>       题目难度
tag               <class 'list'>      题目标签列表


--------------------------------
# 查询
--------------------------------
要查询符合条件的题目，请输入 'query' ，然后输入一个 python3 的表达式。
例：
name == '最优贸易'                    查询名字为'最优贸易'的题目
diff == '提高+/省选-'                 查询难度为'提高+/省选-'的题目
find(name, '最') == -1                查询名字中不含有'最'字串的题目
tag.count('最短路')                   查询含有'最短路'标签的题目'


--------------------------------
# 排序
--------------------------------
要排序题目列表，请输入 'sort' ，然后输入一个 python3 的表达式。
例：
-1 if id1 < id2 else 1                将题目列表按编号递增的顺序排序
-1 if len(tag1) > len(tag2) else 1    将题目列表按标签数量递减的顺序排序


--------------------------------
# strwidth()
--------------------------------
strwidth(s) 返回字符串 s 的长度。
例：
strwidth('153')=3
strwidth('数字')=4
strwidth('一二三12345')=11


--------------------------------
# diffrank()
--------------------------------
diffrank(s) 返回字符串 s 的难度评级。
'入门难度'...'NOI/NOI+/CTSC' 为 0..6 ，其他为 -1 。
例：
strwidth('入门难度')=0
strwidth('普及-')=1
strwidth('普及+/提高')=3


--------------------------------
# getoj()
--------------------------------
getoj(s) 返回字符串 s 的 OJ 名。
支持的 OJ ： LGOJ, SPOJ, POJ, BZOJ, USACO
若找不到，返回 "UNKNOWN"
例：
getoj('LGOJ1038')='LGOJ'
getoj('USACO Section 1.2 A')='USACO'
getoj('BZOJ1001')='BZOJ'


--------------------------------
# 指令
--------------------------------
help                                  显示帮助
query                                 查询符合条件的题目
sort                                  排序题目列表
exit                                  退出程序


--------------------------------
# 其他
--------------------------------
警告：此程序不会阻挡 help() 或其他危险函数的使用。
请在使用时多加注意。
""".strip())

showhelp()

while True:
    try:
        read = input('>>> ').strip()
        if read == 'exit':
            exit()
        elif read == 'query':
            read = input('... ').strip()
            exec(
'''
def func(id, name, diff, tag):
    return {}
'''
.strip().format(read))
            problems = [problem for problem in problem_list if func(problem['id'], problem['name'], problem['diff'], problem['tag'])]
            print('成功查询并返回 {} 个结果:'.format(len(problems)))
            problems.insert(0, {'name':'题目名', 'diff':'难度', 'tag':['标签'], 'id':'编号'})
            idlen = 0
            namelen = 0
            difflen = 0
            for problem in problems:
                idlen = max(idlen, strwidth(problem['id']))
                namelen = max(namelen, strwidth(problem['name']))
                difflen = max(difflen, strwidth(problem['diff']))
            for problem in problems:
                print('{i}{_is}{n}{ns}{d}{ds}{t}'.format(
                    i=color.get('t-'+getoj(problem['id']), '') + problem['id'] + color.get('reset', ''),
                    _is=(idlen-strwidth(problem['id'])+2)*' ',
                    n=problem['name'],
                    ns=(namelen-strwidth(problem['name'])+2)*' ',
                    d=color.get('t-white', '') + color.get('bg-'+problem['diff'], '') + color.get('bright', '') + problem['diff'] + color.get('reset', ''),
                    ds=(difflen-strwidth(problem['diff'])+2)*' ',
                    t=', '.join(problem['tag']),
                    ))
            exec('del func')
        elif read == 'sort':
            read = input('... ').strip()
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
            raise_error('未知指令 \'{}\''.format(read))
    except Exception as e:
        raise_error(str(e))
        # raise_error(str(e))
