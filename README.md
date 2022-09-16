# 2022-rne

## 설치 스크립트
```
git clone https://github.com/oxjihun/ANFConv.git
cd ANFConv
g++ -o ANFConv ANFConv.cpp
cd ..
git clone https://github.com/oxjihun/automate.git
cd automate
chmod +x ./edit_lowmc.sh
chmod +x ./main.sh
chmod +x ./resolve.sh
chmod +x ./sheets.sh
cd ..
git clone --depth 1 https://github.com/meelgroup/bosphorus
cd bosphorus
mkdir build
cd build
cmake ..
make -j4
./bosphorus -h
cd ..
cd ..
git clone https://github.com/LowMC/lowmc.git
git clone https://github.com/oxjihun/lowmc_test.git
rm lowmc/test.cpp
mv lowmc_test/test.cpp lowmc
```