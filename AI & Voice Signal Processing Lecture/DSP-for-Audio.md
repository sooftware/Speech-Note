# 「AI & Voice Signal Processing」 Lecture : DSP for Audio
  
본 글은 광운대학교 전자공학과 박호종 교수님의 강의를 듣고 작성되었음을 밝힙니다.  
  

이제는 오디오에 특화된 DSP로 넘어가보자.

## Short-Time Fourier Transform
  
질문으로 시작하자.  
  
**Quesion** : 아래 두 신호의 spectrum은 어떤 차이를 가지는가?  
  
![image](https://user-images.githubusercontent.com/42150335/79644550-a476d800-81e4-11ea-8dae-c00593ebb35c.png)  
  
위의 두 신호는 분명히 서로 다른 신호이다. 이 신호를 주파수 축에서 바라본다면 어떤 차이가 있을까??  
  
![image](https://user-images.githubusercontent.com/42150335/79644591-e869dd00-81e4-11ea-9676-0c39b9b2e5c1.png)  
  
차이를 찾을 수가 없음을 볼 수 있다. 주파수 성분이 서로 같으므로 당연한 결과이다.  
  
여기서 문제점이 제기된다.  
  
* Fourier Transform은 무한대 시간 영역 적분이다.    
  + Spectral Magnitude는 **전체 시간 영역의 평균적인 주파수 특성**을 보여준다.
  + **Phase**가 시간적 특성 변화 정보를 제공한다.  
    
여기서 Phase는 그냥 넘어가도록 한다.  
  
* 음성/오디오 신호는 시간 진행에 따른 **주파수 성분 변화가 핵심 정보**이다.
  + 시간 진행에 따른 spectrum 정보 변화의 분석이 필요하다.
  + 짧은 시간 영역에 한정된 FT를 실시한다.
    + **Short-Time Fourier Transform (STFT)**
    
* 해당 구간만의 FT를 실시하면 **boundary effect**가 발생한다.
  + Boundary에서의 급격한 신호 변화가 spectrum에 포함됨
  + Window function을 사용하여 Smoothing을 해준다.  
    
![image](https://user-images.githubusercontent.com/42150335/79644736-d6d50500-81e5-11ea-8491-dd3342a1e1c4.png)  
  
실제 신호에 대해서 어떻게 **STFT**가 적용되는지를 살펴보자. 앞에서 말했듯이 전체 시간 영역에 대해서 적분을 하게 되면 전체 시간 영역의 평균적인 주파수 특성만을 보여준다.  

이에 대한 해결책은, 짧은 시간에 대해서 Fourier Transform을 적용하면 된다.  
오른쪽 그림과 같이 원하는 구간을 제외한 부분을 0으로 없애버리고 Fourier Transform을 적용한다.  

여기서 중요한 점은 일부 구간에 대해서만 FT를 적용하는 것이 아니라, 나머지를 0으로 만들고 전체 영역에 대하여 FT를 적용해야한다는 점이다.  

하지만 이 과정에서 새로운 문제점이 제기된다.  

위에서 언급했듯이, 음성/오디오 신호에서는 주파수 성분 변화가 핵심 정보이다.  
근데 위와 같이 원하는 부분만 뚝- 잘라버리면 경계 부분의 순간 변화율이 매우 크게 된다. 이러한 문제를 **Boundary Effect**라고 한다.  

이는 **기존 신호에서는 없던 정보**라는게 핵심이다.  
그렇기 때문에, 이러한 쓸데없는 정보를 최대한 줄여줘야 하는 과제가 생긴다.  
이때 나오는 방법이 **Windowing**이다.  
  
![image](https://user-images.githubusercontent.com/42150335/79645063-f1a87900-81e7-11ea-98b9-c13e41e0c831.png)  
  
왼쪽 그림과 같은 윈도우를 자른 구간에 곱해서 순간 변화율을 Smoothing 해줌으로써 기존에 없던 정보를 최대한 줄여준다. 
  
하지만 이 방법의 단점으로는, 자른 신호의 가운데 부분이 조금 더 강조된다는 단점이 있다. (하나의 장점이 있으면, 하나의 단점이 있다)  
  
![image](https://user-images.githubusercontent.com/42150335/79645325-97a8b300-81e9-11ea-9c64-021c5de016f2.png)  
  
많이 쓰는 윈도우 함수로는 위의 5가지가 있다. 논문 등에 많이 나온다고 하니, 정확한 식은 기억 못하더라도, 이름 정도는 알고 있는게 좋다.  
  
* Window Shape
  
![image](https://user-images.githubusercontent.com/42150335/79645357-c888e800-81e9-11ea-8029-c5e57c6354d7.png)  
