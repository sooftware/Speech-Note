# Kaldi Tutorial
  
RM corpus 소개 및 kaldi 설치  
  
## Kaldi Toolkit
  
Automatic Speech Recognition Toolkit
논문에서도 많이 쓰이는 툴킷. 각종 논문 및 개발에 있어 reference로 사용  
최상단은 Shell Script지만, 내부적으로 C++로 이루어져 있음.  
    
## RM corpus 소개  
  
3시간짜리의 작은 데이터셋 (데이터양이 적기 때문에 바로바로 실습 가능)
  
### LDC (Linguistic Data Consortium)
  
* 음성/음향 및 텍스트 데이터 배포 기관  
  + 음성, 음향, 텍스트 데이터를 전문적으로 수집하여 판매  
  + 언어 연구, 음성 연구, 자연어 처리 연구에 활발히 이용됨
    
### DARPA Resource Management (RM)
  
* 영문으로 구성된 연속음성인식을 위한 corpus
  
Mono channel pcm : 여기서 mono란 채널이 1개라는 의미  
=> 사람 목소리는 하나에서 나오기 때문에 1지만, 음악 같은 경우는 기타 보컬 드럼 등 여러 채널에서 나옴 (보통 모노 채널로 연구를 함)  
=> 추가적으로, 잡음도 녹음을 한다면, 채널 여러개를 사용함  
  
LDC93S3A : LDC에서 93년도에 나온 3번째 버전 Advanced 버젼  
  
* CMVN (Cepstral Mean Variance Normalization)
  
아직 정석은 CMVN을 반영하는것이지만, 요즘 대세는 CMVN을 적용하지 않는 것이 대세이다.  
  
