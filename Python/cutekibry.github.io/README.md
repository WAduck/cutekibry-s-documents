# cutekibry.github.io-source
Source code of cutekibry.github.io.

# Cinccino
An unstable static blog engine which offers Mediawiki-style website and forces you to use Python 3.

**Warning: This module is unstable and not completed.**

**If you want better experience, I advise you to use [Jekyll](https://github.com/jekyll/jekyll), [Pelican](https://github.com/getpelican/pelican) or other engines instead.**

## Not added features
* Template (`{{t}}`)
* Category pages (`Category:categories`)
* Special pages (`Special:random pages`)
* File content (`[[file:image.jpg]]`)
* A lot features

## Added features
* None

## Requires
* Python (`version>=3.4`)
* wikitrans (`python -m pip install wikitrans`)

## Usage
First, clone the repository.

Then, put your files in the `content` directory.

After that, run `make html` to generate the site to the `output` directory.

Run `make serve` to see your website at http://localhost:8000.

Here is my directory (generate by `tree`):
```
.
├── cinccino
│   ├── assets
│   │   ├── catlinks.html
│   │   ├── catlinks-none.html
│   │   ├── help.txt
│   │   ├── navigation-body.html
│   │   ├── navigation-content.html
│   │   ├── navigation-header.html
│   │   ├── poweredby_mediawiki_88x31.png
│   │   ├── redirect.html
│   │   ├── skin.css
│   │   └── wiki.html
│   ├── cinccinoconfig.py
│   ├── make.py
├── content
│   └── wiki
│       ├── Hello world.wiki
│       └── Topic:USACO Training.wiki
├── LICENSE
├── Makefile
└── README.md
```

## Why the name "Cinccino"?
Don't you think Cinccinoes are REALLY, REALLY  ADORABLE?
