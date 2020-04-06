# 「AI & Voice Signal Processing」 Lecture : Application 2
  
본 글은 광운대학교 전자공학과 박호종 교수님의 강의를 듣고 작성되었음을 밝힙니다.  

## Speaker Verification and Identification
  
### Verification (인증)
  
![image](https://user-images.githubusercontent.com/42150335/78555116-50184380-7847-11ea-8ff3-c6c393d6402c.png)  

음성신호에서 개인별 고유 정보를 추출하여 **본인 검증**  

### Identification (인식)  

![image](https://user-images.githubusercontent.com/42150335/78551433-afbf2080-7840-11ea-96f9-176458bae5dd.png)  
  
여러 음성 신호에서 **특정인 검색**  
  
* Ex) Smartphone 지문 인식 문제  
  
![image](https://user-images.githubusercontent.com/42150335/78553517-59ec7780-7844-11ea-8a81-300778187510.png)
  
* Why Bio 인증?  
기존 비밀번호보다 편리?  
  
기존 비밀번호보다 안전?  
   
![image](https://user-images.githubusercontent.com/42150335/78553891-0890b800-7845-11ea-94f4-7acd4be09065.png)
  
Voice를 이용한 보안의 문제점은 테러범의 핸드폰 같은 경우, 지문 혹은 얼굴 인식과 달리 본인이 마음 먹지 않으면 절대 풀 수가 없음.  
  
## Sound Recognition / Detection
  
* 인간과 동일한 sound 정보 인식  
```
Robot

아기 울음소리 / 동물소리 인식

자율주행 
:: 자율주행에서도 소리로 특징을 포착하는 기술이 필요 (구글은 사이렌 소리를 인식)

청각장애
```
  
* 인간 능력 이상의 sound 정보 인식
```
불법 벌목 감청 (구글이 도입)

멸종위기 고래 탐지
```
  
## Music Information Analysis
  
![image](https://user-images.githubusercontent.com/42150335/78554986-1c3d1e00-7847-11ea-94c0-020f85549942.png)
  
음악 검색, Hit 가능성 여부 예측, 인공 작곡 + 감정  
  
* Content 기반으로 Music 검색 / Retrieval
```
노래 일부분의 음만을 가지고 찾고싶은 노래 검색  

표절 확인

자동 노래 선곡 시스템
```
  
## Speech and Audio Coding
  
전송 또는 저장을 위한 디지털 데이터양을 감소시키는 기술
  
=> 거의 완벽하게 산업화에 성공
  
디지털 이동 통신, portable music의 핵심  
  
![image](https://user-images.githubusercontent.com/42150335/78555377-d9c81100-7847-11ea-9987-cdcf3d884ad5.png)
  
* 현재의 연구 동향  
  
모든 종류의 sound를 통합적으로 처리  
(기존에는 speech codec, audio codec으로 구분)  
  
* 국제 기관 (ITU, ISO 등)에서 표준 codec 선정  
  
## 3D Audio / 입체 음향  
  
![image](https://user-images.githubusercontent.com/42150335/78555735-9d48e500-7848-11ea-852b-56129ba59960.png)
  
* Audio for Virtual Reality
  
![image](https://user-images.githubusercontent.com/42150335/78555846-d3866480-7848-11ea-9abf-fa4b18b994c6.png)
  
## 디지털 오디오 방송
  
### 객체(Object) 기반 디지털 오디오 방송  

![image](https://user-images.githubusercontent.com/42150335/78557966-beabd000-784c-11ea-9d56-ca474c336ae5.png)


* 오디오 객체별로 신호 전송  
  
* 사용자가 sound를 임의로 선택하여 청취  
  + Sports 중계 방송, 음악 방송, 드라마  
  + 언어 선택 (외국어로 방송 청취)
  + 입체 음향 청취
    
사용자는 원하는 오디오를 선택하여 청취  
  
## 잡음 제거
  
![image](https://user-images.githubusercontent.com/42150335/78558545-bb651400-784d-11ea-842a-9565d373a9ea.png)
  
잡음을 제거하는 간단한 방법으로 마이크를 여러개 설치한다.  
  
Active Noise Cancellation (ANC)  
=> Airpod Pro에 탑재된 기술 (주변 소음 제거)  
  
![image](https://user-images.githubusercontent.com/42150335/78558732-1860ca00-784e-11ea-9656-f8eab0578c1d.png)

들어오는 소리의 파형과 반대되는 파형을 더해줌으로써 0으로 만들어줌
  
## 기타
  
### 신호 복원 : 왜곡되고 변형된 신호를 원 신호로 복원  
  
### Sound type 분리  
  
### Multimedia DB에서 Audio 특성으로 원하는 장면 검색  
  
### 의료 신호처리  

### 음악 치료   
  
### 음향 장비  
  





