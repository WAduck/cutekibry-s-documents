PROG1=1
PROG2=2
MAKER=maker
seed=1

g++ -o $PROG1 ${PROG1}.cpp
g++ -o $PROG2 ${PROG2}.cpp
g++ -o $MAKER ${MAKER}.cpp
while true; do
    seed=`expr \( $seed \* 173 + 682 \) % 173682999`
    echo $seed > seed
    ./$MAKER < seed > data.in
    ./$PROG1 < data.in > ${PROG1}.out
    ./$PROG2 < data.in > ${PROG2}.out
    result=`diff ${PROG1}.out ${PROG2}.out`
    if [[ $result ]]; then
        echo Uncorrect!!!
        exit
    else
        echo Correct
    fi
done
