if test -d .git
then
    git pull
else
    git clone https://github.com/cutekibry/cutekibry-s-documents.git
fi

if test -d Python/cutekibry.github.io/output/.git
then
    echo Python/cutekibry.github.io/output isn\'t empty.
else
    echo Python/cutekibry.github.io/output is empty.
    cd Python/cutekibry.github.io
    git clone https://github.com/cutekibry/cutekibry.github.io.git
    rmdir output
    mv cutekibry.github.io output
fi
