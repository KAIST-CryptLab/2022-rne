# Author: 20-046 박지훈

# read testcase.txt

i=0;
t=0;
google_sheets="";
while read line; do
    if (( i <= 5 ))
    then
        google_sheets="$google_sheets$line\t";
        if (( i == 5 ))
        then
            t=$line;
        fi
    elif (( 6 <= i )) && (( i < 6 + t ))
    then
        if (( i == 6 ))
        then
            google_sheets="$google_sheets\"";
        fi
        google_sheets="$google_sheets$line";
        if (( i < 6 + t  - 1))
        then
            google_sheets="$google_sheets\n";
        fi
    fi
    i=$(($i+1))
done < ./testcase.txt

google_sheets="$google_sheets\""

printf $google_sheets > sheets.txt