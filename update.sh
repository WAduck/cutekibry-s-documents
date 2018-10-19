if test -d .git
then
    git pull
else
    git clone https://github.com/cutekibry/cutekibry-s-documents.git
fi

if test -d Python/cutekibry.github.io-source/site/.git
then
    echo
else
    cd Python/cutekibry.github.io-source
    git clone https://github.com/cutekibry/cutekibry.github.io
    mv cutekibry.github.io/* site/*
    rm cutekibry.github.io
fi
