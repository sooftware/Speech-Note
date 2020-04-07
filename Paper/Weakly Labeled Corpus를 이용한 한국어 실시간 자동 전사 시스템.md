# Weakly Labeled Corpus를 이용한 한국어 실시간 자동 전사 시스템
  
## 초록
  
본 논문은 YouTube 동영상과 이에 해당하는 자동 생성자막으로 이루어진 weakly labeled corpus를 구축하고, 해당 데이터를 활용하여 음향모델 학습 후 성능 비교를 한 결과를 비교하였다. 제안된 시스템은 CER (Character Error Rate) 기준으로 8%의 우수한 성능을 보였으며, corpus 구축에 사용된 도메인이 아닌 IPA 도메인에서도 CER 5.86%의 준수한 성능을 보였다.  
  
## 서론
  
음성인식 기술은 사람의 발화로부터 나온 음성신호를 분석하여 자동으로 문자열로 변환해주는 기술이다. Automatic Speech Recognition (ASR) 또는 Speech-To-Text (STT) 라고 불린다. 음성인식 기술의 정확성에 관련된 가장 큰 이슈로는 화자별 발성의 차이, 주변 잡음 그리고 인식 가능 어휘의 제한으로 인한 인식 오류 발생 등이 있다.  
  
### Automatic Speech Recognition
  
전통적인 음성인식 시스템은 **Hidden Markov Model (HMM)** 을 이용하여 주어진 음성을 가장 잘 나타내는 상태(문자열)를 찾는 과정이며, **Gaussian Mixture Model (GMM)** 을 이용하여 음성의 분포를 모델링하여 HMM과 결합한 **HMM-GMM** 을 주로 사용하였다. 이후 GMM을 **Deep Neural Network (DNN)** 로 대체한 **HMM-DNN** 모델이 월등히 높은 성능을 낼 수 있다는 연구들이 나왔으며, 최근까지도 **HMM-DNN** 모델은 **State-Of-The-Art (SOTA)** 의 성능을 보이고있다.  
  
#### Online ASR  
  
일반적인 음성인식 방법인 Offline ASR에서는 입력 음성에 대한 출력 텍스트의 반응 속도 (Real-Time Factor; RTF)에 대한 제한이 없다. RTF는 주어진 입력 음성의 길이에 대한 계산 시간으로 정의된다.  
  
Offline ASR에서는 RTF에는 초점을 맞추지 않고 정확성이 중요한 지표로 사용되지만 Online ASR 혹은 Incremental Speech Recognition (ISR)과 같은 실시간 시스템은 디코딩 시간에 대한 RTF를 중요한 지표로 둔다.  
  
#### 스트리밍 음성인식  
  
스트리밍 음성인식은 스트리밍으로 입력되는 오디오에 대하여 오디오가 처리됨에 따라 online ASR의 결과인 문자열을 출력해내는 음성인식 방법을 의미하며 추가적으로 여러 문장에 대한 발성을 인식할 수 있는 음성인식을 말하며 추가적으로 여러 문장에 대한 발성을 인식할 수 있는 음성인식을 말한다.  
  
### Google YouTube 자동 전사 시스템

![image](https://makemoneyskills.com/wp-content/uploads/2019/04/youtube_subtitlee_download_step6.png)

YouTube에서는 Google의 음성인식 기술을 사용해 자동으로 동영상의 자막을 생성해주는 서비스를 제공 중이다. 이러한 자동 자막 생성의 품질은 도메인에 따라 다양하며 뉴스와 같은 도메인에서는 뛰어난 품질을 보여준다.   
  
#### Google Youtube 자동 전사 시스템 명세 
  
Google은 한국어에 대한 자동 전사 시스템의 성능을 밝히지 않고 있으나, 「Neural Speech Recognizer: Acoustic-to-Word LSTM Model for Large Vocabulary Speech Recognition」 논문을 통해 대략적으로 밝히고 있다. 음향 모델은 Connectionist Temporal Classification (CTC)와 Long Short Term Memory (LSTM)을 결합한 CTC-LSTM을 사용하고 있으며, 단어 사전 (Lexicon)으로는 50만 단어급 사전을 사용 중 이다. 자동 전사 시스템의 성능은 영어에 대하여 단어 오류율 (Word Error Rate; WER) 기준 13.4%의 성능을 보이고 있으며 한국어에 대해서는 성능을 밝히고 있지 않으나 YouTube에 업로드 되어있는 뉴스 영상 60개 (1.21시간 분량)에 대하여 음절오류율 (Character Error Rate; CER)을 측정한 결과 8.654%의 성능을 보였다.  
  
#### Weakly Labeled Data
  
Weakly labeled data란 레이블이 존재해야하는 데이터에 대하여 일부의 label 누락된 데이터를 말한다. 반대로 Strong labeled data는 학습에 필요한 모든 정보가 표기 되어있는 자료를 말한다.  

* Strong Labeled Data  
```
미국 남동부 지역을 강타한 토네이도가 남겨놓은 처참한 흔적들입니다
```
* Weakly Labeled Data
```
미국 남동부 지역을 강타 1 토네이도가 남겨놓은 처참한 흔적들이 입니다
```

본 논문은 Google YouTube에서 수집 가능한 영상들과 이들에 대해 자동전사로 생성된 자막 파일을 weakly labeled data로 정의 하도록 한다.  

#### 연구 목표

본 논문은 Google YouTube로부터 수집 가능한 weakly labeled data를 수집하고 이를 음성 인식 학습에 사용 가능한 한국어 weakly labeled corpus를 구축하고 이를 학습에 사용하는 방법을 제안한다.   

## 관련 연구
  
일반적으로 ASR의 학습은 정확한 전사(transcription)를 가진 자료를 필요로한다. 그러나 정확한 전사를 가진 데이터를 수집하고 만드는 것은 높은 비용과 많은 인력을 필요로 하는 작업이므로 비교적 부정확한 전사를 이용하거나, 이미 학습된 ASR 시스템을 이용하여 전사를 만들고 학습하는 방식에 대한 연구들이 있었다.  
  
여러 연구에서 정확한 전사의 학습 자료가 아니더라도 많은 양의 부정확한 전사 자료를 이용함으로써 음성인식 시스템의 성능을 향상시킬 수 있음을 보였다.  
  
### Semi-supervised Learning for ASR
  
부정확한 전사를 이용하더라도 음성인식 시스템의 성능이 향상 될 수 있다는 연구 이후로 학습자료를 늘리기 위한 방식으로 Unsupervised Learning이 제안되었다. 그러나 아예 학습 자료의 label이 없이 군집화하는 방식인 unsupervised learning과는 다르게 이미 label 된 자료를 이용해서 학습한 ASR 시스템을 이용하므로 최근에는 semi-supervised learning으로 불리고있다.  
  
