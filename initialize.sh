rm ../lowmc/test.cpp
cp ../2022-rne/lowmc_test/test.cpp ../lowmc
cd ../2022-rne/ANFConv
g++ -o ANFConv ANFConv.cpp
cd ..
cd automate
chmod +x ./edit_lowmc.sh
chmod +x ./main.sh
chmod +x ./resolve.sh
chmod +x ./sheets.sh