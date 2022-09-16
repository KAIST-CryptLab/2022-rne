# ANFConv

이 리포지토리에 있는 코드는 2022 R&E 활동의 일환으로 작성되었습니다. 

2022년 09월 16일, RnE 관련 코드를 모두 [RnE 리포지터리(Private)](https://github.com/KAIST-CryptLab/2022-rne)로 옮겼습니다. 

`ANFConv.cpp`: 평문과 암호문의 쌍들로부터 ANF를 생성하는 코드입니다. 21-025 김유성 학생이 원본을 작성하였고, 20-046 박지훈 학생이 실험 환경에 맞게 일부 수정하였습니다. 여기에 올린 것이 실험에 적합하도록 수정된 버전입니다. 

`Matrix_generator.py`: 행렬과 상수를 생성하는 코드로, ANFConv.cpp가 작동할 때 필요합니다. [LowMC](https://github.com/LowMC/lowmc)의 `generate_matrices.py` 파일을 변형하였습니다. 
