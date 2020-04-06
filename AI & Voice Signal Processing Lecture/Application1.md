# 「Ai & Voice Signal Processing」 Lecture: Application 1  
  
## 음성/오디오/sound 특성

* 방송 / 통신 / 엔터테인먼트의 핵심 기술
* 학계/산업계의 전문 엔지니어 부족
* Art, 취미 활동과 관련된 기술
* 음성에서 언어의 종속성  
음성 이해, 음성 신호의 품질 및 명료도 평가에서 중요한 요인   
* 음성은 대표적인 생체신호  
음성 기반 헬스케어, 장애인을 위한 복지 기술  
* Data 양 : V >> A (4차원 : 2차원)
* 심리적 민감도 : V < A  
특정 sound에 대한 거부감 존재   
심리 변화에 큰 영향 : 공포 영화에서 분위기 조정  
* 요구 품질 : V < A  
일반적으로 낮은 화질은 허용되지만 낮은 음질은 허용되지 않음   
* 멀티미디어에서의 독립성 : V < A  
  
## Applications - Speech Synthesis
  
기계를 이용하여 언어 정보를 가지는 음성 신호를 생성 : Text-To-Speech (TTS)
  
![tts](https://user-images.githubusercontent.com/42150335/78545239-6f5aa500-7836-11ea-8851-b87875dd586f.png)
  
음정을 맞추기는 쉽지만, 발음을 정확히 맞추기가 어렵다.  
  
- Before 2010 : digital waveform 연결, boundary smoothing  
  
![tts-before-2010](https://user-images.githubusercontent.com/42150335/78545482-cfe9e200-7836-11ea-93e1-dc07293a672c.png)
  
음절 단위로 미리 녹음해놓고 파형을 저장해놓는다.  
Text를 보고 미리 녹음해놓은 파형을 적절하게 이어붙인다.  
  
=> 부자연스러움
  
이러한 부자연스러움을 해결하기 위해 단어 단위로 녹음하는 것이 더 자연스러웠음
  
하지만 자연스럽게 하는 과정이 굉장히 어렵다.  
  
Example)  
```
고기

소고기
돼지고기

불고기

물고기
=> 물꼬기라고 발음이 됨 ※ 문제가 됨 ※
```

- After 2010 : AI-based waveform generation  
  
현재 AI를 이용하여 상용화가 가능할 정도의 음질이 나오게 됨
  
* 부모가 들려주는 동화책  
* 죽은 사람의 목소리 재현 : 신체 구조로부터 음색 추정  
  
## Applications - Music Synthesis
  
전자장치를 이용하여 music signal 합성
(쉽게 말하면 전자 키보드)  
  
## Applications - Sound for Game and Animation
  
게임이나 애니메이션 사운드를 직접 만드는 기술  
(물건이 떨어지는 소리, 발자국 소리 등..)  

* 기존에는 미리 녹음된 waveform을 상황에 맞추어 출력  
=> 단순한 sound 반복에 의한 피로감  
  
* Sound 합성 엔진 이용  
물체 특성과 움직임에 따라 수학적으로 sound를 합성  
  
## Applications - Speech Recognition  
  
기계가 음성 신호에 포함되어 있는 언어정보를 인식  
  
![stt](https://user-images.githubusercontent.com/42150335/78549178-ebf08200-783c-11ea-9dfa-3922f0d77404.png)
  
* Human-machine interface의 핵심 기술  
휴대전화에서 mic 입력으로 문자 및 명령 입력  
장애인, 특수 환경에서의 기기 동작  
지능형 로봇  
* 언어에 대한 지식 필요  
* 감정 인식에 대한 연구 진행  
* 문제점  
기술적 한계 : 사용자는 매우 높은 인식률 요구  
사용에 대한 거부감 (의외로 불편)  
더 편리한 다른 방법이 있으면 사용하지 않음  
=> 말보다 키보드 or 마우스 입력이 편하다


* 자연어 (Natural Language) 인식  
  
휴대폰에서 많이 사용하는 이유는, 조그마한 휴대폰에 타이핑하기가 힘들기 때문이다.  
음성인식은 항상 첫번째 옵션이 아닌, 두번째 세번째 옵션인 것을 이해해야 한다.  
  
## AI Assistant  
  
아마존의 에코, SK의 누구, KT의 기가지니 등 최근 많이 볼 수 있는 제품  
  
생각보다 불편한 탓에 아직 활용가치가 높지 않다.  
  
* 문제점 1  
  
아마존 인형의집 주문 사건  
  
TV에서 나온 소리를 인식해서, 미국 전역에 장난감을 주문한 사건  
  
* 문제점 2
  
화자 인식
  
 ![assistant-problem](https://user-images.githubusercontent.com/42150335/78549804-e8112f80-783d-11ea-83fd-3f6bb63870c4.png)  
   
=> 여기서 "내"가 누군지 모른다.
  
* Privacy Issue  
```  
항상 Sound를 수집하고 있다?  
  
수집은 하지만 폐기한다?  
  
일상 대화  
  
인간 인식
```
  
Camera (CCTV)에 비하여 위험성은 인지 못함  
  
## 자동차에서의 음성 인식  
  
자동차 내에서는 "복잡한 입력보다는 음성으로 입력을 하자"라는 논리가 성립이 됨  
  
But! 자동차라는 이유로 생기는 문제점이 있음  
  
* 다양한 잡음 (자동차 잡음, 라디오 소리, 대화 소리 등 ...)  
* 원거리 마이크  
* 버튼보다 불편함  
  
## Very Efficient Speech Communication
  
* 파형 전송 없이 텍스트만 전송하므로 정보량이 매우 적음  
* 자연스러운 통신을 위하여 감정과 Speaker 특성 전송  
  
![image](https://user-images.githubusercontent.com/42150335/78550813-b8fbbd80-783f-11ea-9ad4-c97440914b0c.png)  
  
여기에 기계 번역까지 더해진다면, 어느 언어와도 편리한 통신이 가능함  
  
아직은 Ideal한 얘기지만, 이렇게 될 것이다.  