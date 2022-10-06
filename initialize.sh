rm lowmc/test.cpp
cp lowmc_test/test.cpp lowmc
cd ANFConv
g++ -o ANFConv ANFConv.cpp
cd ..
cd automate
chmod +x ./edit_lowmc.sh
chmod +x ./main.sh
chmod +x ./resolve.sh
chmod +x ./sheets.sh