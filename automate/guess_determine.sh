# Author: 20-046 박지훈

plaintexts=();

# read testcase.txt

i=0;
t=0; # 테케 수
while read line; do
    if (( i == 0 ))
    then numofboxes=$line;
    elif (( i == 1 ))
    then blocksize=$line;
    elif (( i == 2 ))
    then keysize=$line;
    elif (( i == 3 ))
    then rounds=$line;
    elif (( i == 4 ))
    then key=$line;
    elif (( i == 5 ))
    then t=$line;
    elif (( 6 <= i )) && (( i < 6 + t ))
    then plaintexts+=($line);
    fi
    i=$(($i+1))
done < ./testcase.txt

# edit_lowmc.sh

./edit_lowmc.sh $numofboxes $blocksize $keysize $rounds

# get ciphertexts

ciphertexts=();

for ((i=0; i<$t; i++))
    do
        ciphertexts+=($({ echo $key; echo ${plaintexts[i]}; } | ../lowmc/LowMC))
    done

# generate input text for ANFConv

input="$numofboxes\n$blocksize\n$keysize\n$rounds\n$t\n"

for ((i=0; i<$t; i++))
    do
        input="$input${plaintexts[$i]}\n${ciphertexts[$i]}\n"
    done

printf $input > generated_input.txt
printf $input | ../ANFConv/ANFConv > /dev/null

rm Kmatrix.txt
rm Lmatrix.txt
rm roundconstant.txt

# resolve.sh

./resolve.sh $keysize > resolve_result.txt