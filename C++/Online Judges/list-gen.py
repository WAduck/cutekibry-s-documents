#!/usr/bin/python3
from pathlib import *
import os

try:
    import colorama
    colorama.init(autoreset=True)
    def raise_warning(message):
        print(colorama.Fore.YELLOW + 'Warning: ' + message)
except ModuleNotFoundError:
    def raise_warning(message):
        print('Warning: ' + message)

root = Path()
problem_list = list()
for dir in root.iterdir():
    if dir.is_dir():
        print('Processing folder \'{}\'...'.format(dir))
        config = [file for file in list(dir.iterdir()) if file.name == 'config.txt']
        if not config:
            raise_warning('Folder \'{}\' does not content config.txt. Skip processing.'.format(dir))
            continue
        config = config[0]
        file = open(config, 'r', encoding='utf-8')
        try:
            params = eval(''.join(file.readlines()))
            params['id'] = params.get('id', '无id参数')
            params['name'] = params.get('name', str(dir))
            # print(type(params), type(dict()), type(params) != type(dict()))
            if type(params) != type(dict()):
                raise TypeError
            params['diff'] = params.get('diff', '无diff参数')
            params['tag'] = params.get('tag', '无tag参数')
            problem_list.append(params)
        # except TypeError:
        #     raise_warning('\'{}\' contents {} instead of {}. Skip processing.'.format(config, type(params), type(dict())))
        except Exception as e:
            raise_warning('An exception was raised while processing \'{}\':\n{}\nSkip processing.'.format(config, e))
problem_list.sort(key=lambda x: x['id'])
with open('list.txt', 'w', encoding='utf-8') as output:
    try:
        from pprint import pprint
        pprint(problem_list, stream=output)
    except ModuleNotFoundError:
        print(str(problem_list), file=output)
