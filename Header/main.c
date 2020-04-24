/*
	AI - Speech Homework #1

	Kwangwoon Univ. Electronic-Communication Senior 
	- 2014707073 Soohwan Kim 
*/

#include "signal.h"

#define N_POINT			1600  
#define N_EXG 			8
#define SAMPLE_RATE 	16000

int skip[N_EXG] = { 
	0.3 * SAMPLE_RATE,   
	0.5 * SAMPLE_RATE,   
	0.2 * SAMPLE_RATE,   
	0.1 * SAMPLE_RATE,   
	0.1 * SAMPLE_RATE,   
	0.2 * SAMPLE_RATE,   
	0.2 * SAMPLE_RATE,   
	0.1 * SAMPLE_RATE    
};
FILE* fin;
float comp_freq(int index);


int main() {
	float note_freq[N_EXG] = { 0.0, };

	fopen_s(&fin, "input16kraw", "rb");

	for (int i = 0; i < N_EXG; i++){
		note_freq[i] = comp_freq(i);
		printf("%d ", note_freq[i]);
	}


	fclose(fin);
	return 0;
}


float comp_freq(int index) {
	float signal[N_POINT];
	float spec_real[N_POINT];
	float spec_imag[N_POINT];
	float spec_magn[N_POINT];
	float freq = 0.0;
	short data = 0;
	int k = 0;

	printf("%d", skip[index]);

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
