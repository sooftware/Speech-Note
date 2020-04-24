/*
	AI - Speech Homework #1

	Kwangwoon Univ. Electronic-Communication Senior 
	- 2014707073 Soohwan Kim 
*/

#include "signal.h"

#define N_POINT			1600  
#define N_EXG 			8
#define N_READ 			1
#define SAMPLE_RATE 	16000

FILE* fin;
float comp_freq(int index);
int skip[N_EXG] = { 
	SAMPLE_RATE * 0.28,   // 0.35
	SAMPLE_RATE * 0.4,   // 0.85
	SAMPLE_RATE * 0.22,   // 1.17
	SAMPLE_RATE * 0.16,   // 1.43
	SAMPLE_RATE * 0.1,   // 1.62
	SAMPLE_RATE * 0.07,   // 1.87
	SAMPLE_RATE * 0.17,   // 2.14
	SAMPLE_RATE * 0.18    // 2.42
};


int main() {
	float note_freq[N_EXG] = { 0.0, };

	fopen_s(&fin, "input16k.raw", "rb");

	for (int i = 0; i < N_EXG; i++){
		note_freq[i] = comp_freq(i);
		printf("%.2f ", note_freq[i]);
	}

	system("pause");
	fclose(fin);
	return 0;
}


float comp_freq(int index) {
	float signal[N_POINT];
	float spec_real[N_POINT], spec_imag[N_POINT], spec_magn[N_POINT];
	float freq = 0.0;
	short data = 0;
	int k = 0;

	/* Skip to the start */
	for (int n = 0; n < skip[index]; n++) 
		fread(&data, SHORT_SIZE, N_READ, fin);

	for(int n = 0; n < N_POINT; n++){
		fread(&data, SHORT_SIZE, N_READ, fin);
		signal[n] = (float)data;
	}

	/* N point Discrete Fourier Transform */
	dft(signal, spec_real, spec_imag, spec_magn, N_POINT, "hamming");
	k = argmax_magnitude(spec_magn, N_POINT);
	freq = convert_hertz(k, SAMPLE_RATE, N_POINT);

	return freq;
}
