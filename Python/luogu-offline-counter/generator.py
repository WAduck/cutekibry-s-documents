#!/usr/bin/python
import requests

# Some useful simple functions
def readfile(file):
    with open(file, 'r', encoding='utf-8') as f:
        s = ''.join(f.readlines())
    return s

def writefile(file, text):
    with open(file, 'w', encoding='utf-8') as f:
        f.write(text)

problemlist = {}
headers = {
    'user-agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.75 Safari/537.36',
}


i = 1
while True:
    r = requests.get('https://www.luogu.org/problemnew/lists', headers=headers, params={'page':i})
    for re.findall(string='', pattern='<div class="am-g lg-table-row lg-table-bg0">')
