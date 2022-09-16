# Author: 20-046 박지훈

# Modified from https://github.com/meelgroup/bosphorus

echo "Started solving ANF at" $(date)
{ time ../bosphorus/build/bosphorus --anfread ANF.txt --solvewrite solution > ./resolve_bosphorus.txt; } 2>&1
echo ""
echo "Finished solving ANF at" $(date)
echo ""

keysize=$1
echo "keysize: $keysize"

sol=$(<solution)
if [ "$sol" = "Solution UNSAT" ]
then
    echo "There are no possible keys. "
    exit 0
fi
sol_arr=($sol)
echo -n "The key bits are "
for ((i=-1; i>=-$keysize; i--))
    do
        if [ ${sol_arr[$i]::1} = "-" ]
        then
            echo -n "0"
        else
            echo -n "1"
        fi
    done
echo ". "