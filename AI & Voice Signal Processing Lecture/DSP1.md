# 「AI & Voice Signal Processing」 Lecture : DSP 1
  
본 글은 광운대학교 전자공학과 박호종 교수님의 강의를 듣고 작성되었음을 밝힙니다.  
  
## DSP Review  
  
### Time-to-Frequency transform

* Continuous-Time Fourier Transform, **CTFT**
* Discrete-Time Fourier Transform, **DTFT**
* Discrete Fourier Transform, **DFT**

### System Equation
  
* Frequency Response
* z-transform
  
## CTFT and DTFT
  
### Continuous-Time Fourier Transform (CTFT)

![image](https://user-images.githubusercontent.com/42150335/78560266-d08f7200-7850-11ea-930a-c4dc16410ccf.png)
  
* ω = 2πf
  
* X(f) : Spectrum
  
* x(t) : Signal
  
* X(f)식 해석  
  
**basis signal**  : 주파수를 정의하는 가장 기본적인 식 (f0는 주파수)  
  
**correlation** : 2개의 시그널을 곱하고 전체 적분을 취하면 그것이 곧 두 신호의 비슷한 정도를 나타낸다.  
  
x(t)에 f0가 얼마나 들어있는지를 correlation으로 측정한다.  
(Conjucate를 취해줘서 -j2πft로 바뀜)  
  
* x(t)식 해석
  
역변환의 관계를 이용한 식
  
### Conversion from x(t) to x[n]

![image](https://user-images.githubusercontent.com/42150335/78560292-ddac6100-7850-11ea-8c23-e7da693d1bfd.png)
  
1. Analog Signal을 주기 T마다 Sampling을 한다.  
  
2. 축을 t에서 n으로 변환시킨다.  
  
주의할 점은 n축일때에 1이 1초일때가 아니라는 점.  
=> 우리는 샘플 주기를 모른다면, 몇초인지를 알 수 있다.  
  
### Discrete-Time Fourier Transform (DTFT)  
  
![image](https://user-images.githubusercontent.com/42150335/78560748-86f35700-7851-11ea-865e-7946c84988a6.png)
  
* **중요 포인트 1**  
  
시간 축에서 T마다 샘플링을 하게 되면, 기존 스펙트럼이 1 / T 를 주기로 반복되고 크기는 1 / T로 줄어든다.  
  
1 / T는 주파수를 의미하기도 한다.  
=> 1초에 샘플을 몇개 얻어오느냐  
  
* **중요 포인트 2**  
  
주기 T가 1로 1 / T배 줄어들게되면, 스펙트럼은 반대로 T배만큼 늘어나게 된다.  
  
3번째 그림의 f는 주파수가 아닌 cucle per sample이라는 새로운 f임 주의 !!  
  
* **중요 포인트 3**

중간과정을 생략한채 보게 되면, 기존 스펙트럼이 T배 벌어지고, 1마다 반복되게 된다.  
  
(a가 Ta가 되고, 1마다 반복된다)
  
* **문제 1**  
  
3번째 그림의 1을 가르키면서 몇 Hz냐고 묻는다면, Sampling 주파수에 해당한다 !!  
  
### Conclusion

결국 CTFT와 DTFT는 같은 것이지만, Continuous하냐, Discrete하냐에 따라서 Sigma를 해주느냐, Summation을 해주느냐만이 다른 것이다.  
  
![image](https://user-images.githubusercontent.com/42150335/78562135-d9ce0e00-7853-11ea-8fa4-64d5969a5a3d.png)  
  





