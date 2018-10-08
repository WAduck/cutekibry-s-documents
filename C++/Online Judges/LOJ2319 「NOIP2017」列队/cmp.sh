g++ -o 2319 2319.cpp
g++ -o brust brust.cpp
g++ -o maker maker.cpp
seed=6827162
i=1
while [[ true ]]; do
    seed=`expr \( $seed \* 173 + 682 \) % 173682999`
    echo $seed > seed
    ./maker < seed > data.in
    ./2319 < data.in > 2319.out
    ./brust < data.in > brust.out
    output=`diff 2319.out brust.out`
    # echo $output
    if [[ $output ]]; then
        echo $i Uncorrect!!!
        break
    else
        echo $i correct
    fi
    i=`expr $i + 1`
done
rm 2319 brust maker seed
