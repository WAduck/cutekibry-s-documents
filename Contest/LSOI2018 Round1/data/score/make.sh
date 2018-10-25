g++ -o maker maker.cpp
rm -rf seed
echo 71321 > seed
./maker < seed > score7.in
rm -rf seed
echo 6999 > seed
./maker < seed > score8.in
rm -rf seed
echo 71363221 > seed
./maker < seed > score9.in
rm -rf seed
echo 9221188 > seed
./maker < seed > score10.in

g++ -o score score.cpp -DSTDIO
./score < score7.in > score7.out
./score < score8.in > score8.out
./score < score9.in > score9.out
./score < score10.in > score10.out
