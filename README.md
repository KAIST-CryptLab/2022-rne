# 2022-rne

## 설치 스크립트
이 리포지토리는 KAIST 부설 한국과학영재학교 20-046 박지훈, 21-025 김유성, 21-117 허준혁의 RnE 활동의 일환으로 작성된 코드입니다. 
주어진 평문-암호문 순서쌍을 ANF형태로 바꾸기 위한 ANFConv, LowMC 암호화 코드를 연구에 맞는 방향으로 변형한 코드, 그리고 자동화 코드로 이루어져 있습니다.
아래는 설치를 위한 스크립트입니다.

```
git clone --depth 1 https://github.com/meelgroup/bosphorus
cd bosphorus
mkdir build
cd build
cmake ..
make -j4
./bosphorus -h
cd ..
cd ..
```
```
git clone https://github.com/LowMC/lowmc.git
```
```
git clone https://github.com/KAIST-CryptLab/2022-rne.git
rm lowmc/test.cpp
mv 2022-rne/lowmc_test/test.cpp lowmc
cd 2022-rne/ANFConv
g++ -o ANFConv ANFConv.cpp
cd ..
cd ..
cd 2022-rne/automate
chmod +x ./edit_lowmc.sh
chmod +x ./main.sh
chmod +x ./resolve.sh
chmod +x ./sheets.sh
cd ..
cd ..
```

