# 2022-rne

이 리포지토리는 KAIST 부설 한국과학영재학교 20-046 박지훈, 21-025 김유성, 21-117 허준혁의 RnE 활동의 일환으로 작성된 코드입니다. 
주어진 평문-암호문 순서쌍을 ANF형태로 바꾸기 위한 ANFConv, LowMC 암호화 코드를 연구에 맞는 방향으로 변형한 코드, 그리고 자동화 코드로 이루어져 있습니다.

## 설치 방법

이 리포지토리를 clone한 다음, `2022-rne` 폴더 안에 [Bosphorus](https://github.com/meelgroup/bosphorus)와 [LowMC](https://github.com/LowMC/lowmc)를 설치해야 합니다. 

### Bosphorus 설치

[Building, Testing, Installing](https://github.com/meelgroup/bosphorus#building-testing-installing)를 참고합니다. 

* Install dependencies: 
```
sudo apt-get install build-essential cmake zlib1g-dev \
    libboost-program-options-dev libm4ri-dev libboost-test-dev
```

* Install BRiAl: `apt install libbrial-dev`

* Install CryptoMiniSat: 
```
git clone --depth 1 https://github.com/msoos/cryptominisat.git
cd cryptominisat
mkdir build
cd build
cmake ..
make -j4
sudo make install
```

* Build Bosphorus
```
git clone --depth 1 https://github.com/meelgroup/bosphorus
cd bosphorus
mkdir build
cd build
cmake ..
make -j4
./bosphorus -h
```

### LowMC 설치
```
git clone https://github.com/LowMC/lowmc.git
```

### 설치 스크립트
```
2022-rne
|- ANFConv
|- automate
|- bosphorus
|- lowmc
|- lowmc_test
|- initialize.sh
|- README.md
```
파일 구조가 위와 같음을 확인한 다음에 `initialize.sh`을 실행하면 됩니다. 