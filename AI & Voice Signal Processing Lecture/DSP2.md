# 「AI & Voice Signal Processing」 Lecture : DSP 2
  
본 글은 광운대학교 전자공학과 박호종 교수님의 강의를 듣고 작성되었음을 밝힙니다.  
  
## DFT (Discrete Fourier Transform)
  
Digital 처리를 위하여 time와 frequency domain에서 모두 **sampling**  
  
![image](https://user-images.githubusercontent.com/42150335/78664225-88cf2000-790e-11ea-97f9-b045bfaa45d7.png)  
  
f축에서 1 / N 간격으로 샘플링을 하게 되면 샘플한 결과는 주기마다 N개가 된다.  
이때 샘플링을 했으므로 축은 f -> k로 변하게 된다.  

이전 CTFT와 같이, 1 / N마다 샘플링을 하게 되면 반대 도메인에서 N마다 반복하게 된다.  

![image](https://user-images.githubusercontent.com/42150335/78664562-3c381480-790f-11ea-845a-08b0022d3aee.png)
  
* t축에서 샘플링을 했기 때문에 f축에서 반복이 일어난다. 또한 t축은 n축으로 변하게 된다.  
* f축에서 샘플링을 했기 때문에 n축에서 반복이 일어난다. 또한 f축은 k축으로 변하게 된다.  

![image](https://user-images.githubusercontent.com/42150335/78664917-efa10900-790f-11ea-88d5-232526cb7e1d.png)


사실 x[n]과 X(k)는 서로 연관이 있지 않다. x[n]은 X(f)와, x_hat[n]은 X(k)와 연관이 있을 뿐이다.   
하지만 x[n]에서 X(k)로의 변환이 필요하니 조금 억지로나마 수학적으로 관계를 정의했다.  
=> 이것을 **DFT (Discrete Fourier Transform)** 이라고 한다.  
  
여기서 이렇게 변환이 가능하게한 트릭이 뭔지 살펴보자.  
x[n]과 X(k)는 서로 관계가 없다. 하지만 어차피 일정 부분의 반복일 뿐이다.  
그러므로, 반복되는 부분은 새로운 정보가 있지 않다. => 반복이 되는 내용만 알면 된다.  
  
![image](https://user-images.githubusercontent.com/42150335/78665186-61795280-7910-11ea-86dc-36622103938e.png)
  
여기서 어떤 지점을 범위로 잡느냐하면, [0, N-1]을 범위로 잡는 것을 선호한다고 한다.  
  

f
