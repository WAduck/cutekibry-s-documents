#!/usr/bin/python
import sys
import os
import shutil
import re
from pathlib import *
from cinccinoconfig import *
from wikitrans.wiki2html import HtmlWikiMarkup


# Some useful simple functions
def readfile(file):
    with open(file, 'r', encoding='utf-8') as f:
        s = ''.join(f.readlines())
    return s

def writefile(file, text):
    with open(file, 'w', encoding='utf-8') as f:
        f.write(text)

def copytree(src, dest):
    if dest.is_file():
        dest.unlink()

    if src.is_file():
        if dest.is_dir():
            dest.rmdir()
        shutil.copyfile(src.as_posix(), dest.as_posix())
    else:
        if not dest.exists():
            dest.mkdir()
        for dir in src.iterdir():
            copytree(dir, dest.joinpath(dir.name))

HELP = readfile('assets/help.txt')
WIKIHTML = readfile('assets/wiki.html')
NAVIGATIONBODY = readfile('assets/navigation-body.html')
LICONTENT = readfile('assets/li-content.html')
NAVIGATIONHEADER= readfile('assets/navigation-header.html')
CATLINKS = readfile('assets/catlinks.html')
CATLINKSNONE = readfile('assets/catlinks-none.html')
CATEGORIES = {}
ARTICLES = []

# Show help
if sys.argv.count('-h') or sys.argv.count('--help') or len([x for x in sys.argv if x[0]!='-']) < 3:
    print(HELP)
    exit(0)


# Remake the wiki pages and count the other informations
def resolve(html):
    categories = []
    for category in re.findall(pattern='\<a href\=\"{siteurl}\/wiki\/[^"]*\"\>Category:[^<]*</a>'.format(siteurl=SITEURL), string=html):
        x = category[category.find('>')+1:]
        x = x[:x.find('<')]
        if x[0] != ':':
            categories.append(x[x.find(':')+1:])
            html = html.replace(category, '')
        else:
            x = category.replace(x, x[1:])
            html = html.replace(category, x)
    for precode in re.findall(pattern='\<pre\>\<code\>[^<]*\<\/code\>\<\/pre\>', string=html):
        html = html.replace(precode, precode[5:-6])
    return (html, categories)


# Calculate WIKINAVIGATION and WIKIFOOTER
WIKINAVIGATION = ''
temp = ''
for x in NAVIGATION:
    if x['type'] == 'header':
        if temp:
            WIKINAVIGATION += NAVIGATIONBODY.format(content=temp)
            temp = ''
        WIKINAVIGATION += NAVIGATIONHEADER.format(lang=LANG, content=x['content'])
    else:
        temp += LICONTENT.format(content=x['content'], link=x['link'])
if temp:
    WIKINAVIGATION += NAVIGATIONBODY.format(content=temp)
    temp = ''
WIKIFOOTER = ''.join([LICONTENT.format(content=x['content'], link=x['link']) for x in FOOTER])


src = Path(sys.argv[1])
dest = Path(sys.argv[2])

if dest.joinpath('wiki').is_dir():
    shutil.rmtree(dest.joinpath('wiki').as_posix())
copytree(src, dest)

# Add assets
assets = dest.joinpath('assets')
if not assets.exists():
    assets.mkdir()
writefile(assets.joinpath('skin.css').as_posix(), readfile('assets/skin.css').replace('{wikilogo}', WIKILOGO))
shutil.copy('assets/poweredby_mediawiki_88x31.png', assets.joinpath('poweredby_mediawiki_88x31.png').as_posix())
writefile(dest.joinpath('index.html'), readfile('assets/redirect.html').format(mainpage=MAINPAGE))

# Generate wiki pages
wiki = dest.joinpath('wiki')
if not wiki.exists():
    print('Error: "wiki" directory doesn\'t exist.')
    print('Quit.')
    exit(0)

for file in wiki.iterdir():
    if file.is_file() and (file.suffix == '.wiki' or file.suffix == '.mediawiki'):
        with file.open() as f:
            parser = HtmlWikiMarkup(file=f, html_base='/wiki/', image_base='/assets/', media_base='/assets/')
            parser.parse()
            html = str(parser)
            result = resolve(html)
            html, categories = result
            if categories:
                WIKICATLINKS = CATLINKS.format(content=''.join([LICONTENT.format(content=x, link='/wiki/Category:'+x) for x in categories]))
            else:
                WIKICATLINKS = CATLINKSNONE
            for category in categories:
                if not CATEGORIES.get(category):
                    CATEGORIES[category] = []
                CATEGORIES[category].append(file.with_suffix(''))
            html = WIKIHTML.format(content=html,
                                   title=file.with_suffix('').name,
                                   wikiname=WIKINAME,
                                   lang=LANG,
                                   mainpage=MAINPAGE,
                                   navigation=WIKINAVIGATION,
                                   footer=WIKIFOOTER,
                                   catlinks=WIKICATLINKS)
        file = file.with_suffix('')
        if file.is_file():
            file.unlink()
        elif file.is_dir():
            shutil.rmtree(file.as_posix())
        file.mkdir()
        writefile(file.joinpath('index.html').as_posix(), html)
        ARTICLES.append(file.name)


ARTICLES = sorted(ARTICLES)


# Generate Special:AllPages
SPECIALALLPAGES = readfile('assets/Special:AllPages.html')
specialallpagesdir = wiki.joinpath('Special:{}'.format(SPECIALPAGES['AllPages'][1]))
if specialallpagesdir.is_dir():
    shutil.rmtree(specialallpagesdir.as_posix())
elif specialallpagesdir.is_file():
    specialallpagesdir.unlink()
specialallpagesdir.mkdir()
id = 1
templist = ARTICLES.copy()
length = len(templist)
while templist:
    PAGELINK = ''
    pagelistlen = min(length, 100)
    if id > 1:
        PAGELINK += LICONTENT.format(content='上一页',
                                     link='/wiki/Special:{}/{}'.format(SPECIALPAGES['AllPages'][1], str(id-1)))
    if length > 100:
        PAGELINK += LICONTENT.format(content='下一页',
                                     link='/wiki/Special:{}/{}'.format(SPECIALPAGES['AllPages'][1], str(id+1)))
    html = SPECIALALLPAGES.format(pagelink=PAGELINK,
                                  content=''.join([LICONTENT.format(content=x, link='/wiki/'+x) for x in templist[:pagelistlen]]))
    html = WIKIHTML.format(content=html,
                           title='Special:{}'.format(SPECIALPAGES['AllPages'][0]),
                           wikiname=WIKINAME,
                           lang=LANG,
                           mainpage=MAINPAGE,
                           navigation=WIKINAVIGATION,
                           footer=WIKIFOOTER,
                           catlinks=CATLINKSNONE)
    specialallpagesdir.joinpath(str(id)).mkdir()
    writefile(specialallpagesdir.joinpath(str(id)+'/index.html').as_posix(), html)
    length -= pagelistlen
    templist = templist[pagelistlen:]
    id += 1
shutil.copyfile(specialallpagesdir.joinpath('1/index.html').as_posix(), specialallpagesdir.joinpath('index.html').as_posix())
