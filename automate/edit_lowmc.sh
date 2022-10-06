# Author: 20-046 박지훈

# cp ../lowmc/LowMC_original.h ../lowmc/LowMC.h

cu="const unsigned "

numofboxes=$1
blocksize=$2
keysize=$3
rounds=$4

sed -i "8s/.*/${cu}numofboxes = ${numofboxes}\;/;
        9s/.*/${cu}blocksize = ${blocksize}\;/;
        10s/.*/${cu}keysize = ${keysize}\;/;
        11s/.*/${cu}rounds = ${rounds}\;/;" ../lowmc/LowMC.h

g++ ../lowmc/LowMC.cpp ../lowmc/test.cpp -o ../lowmc/LowMC