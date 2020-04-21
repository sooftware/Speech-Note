/*
	code made by Soohwan Kim @ SPOKEN LANGUAGE LAB	

	- resume: https://sooftware.github.io/
	- github profile: https://github.com/sooftware
	- naver blog: https://blog.naver.com/sooftware
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SHORT_SIZE 	2
#define N_READ 		1
#define PI 			3.14

float* get_window(char* win_type, int win_length, int N);
float* windowing(float* signal, float* window, int win_length);
void n_dft(float* signal, float* spec_real, float* spec_imag, int N, char* win_type);
int argmax_magn(float spec_magn[], int N);
float get_freq();


/* get window ex) hamming, hanning, etc ... */
float* get_window(char* win_type, int win_length) {
	float* window = NULL;

	window = (float*)malloc(sizeof(float) * win_length);

	if (!strcmp(win_type, "hamming")) {
		for(int n = 0; n < win_length; n++)
			window[n] = 0.54 - 0.46 * cos(2 * PI * n / (win_length - 1));
	}
	else if (!strcmp(win_type, "hanning")) {
		for(int n = 0; n < win_length; n++)
			window[n] = 0.5 - 0.5 * cos(2 * PI * n / (win_length - 1));
	}
	else if (!strcmp(win_type, "rectangular")) {
		for(int n = 0; n < win_length; n++)
			window[n] = 1.0;
	}
	else if (!strcmp(win_type, "blackman")) {
		for(int n = 0; n < win_length; n++)
			window[n] = 0.42 - 0.5 * cos(2 * PI * n / (win_length - 1)) + 0.08 * cos(4 * PI * n / (win_length - 1));
	}
	else if (!strcmp(win_type, "sine")) {
		for(int n = 0; n < win_length; n++)
			window[n] = sin(PI * (n + 0.5) / win_length);
	}
	else{
		printf("%s is not Supported\n", win_type);
	}

	return window;
}


float* windowing(float* signal, float* window, int win_length){
    for(int n = 0; n < win_length; n++)
        signal[n] *= window[n];

    return signal;
}


/* N-Point Discrete Fourier Transform */
void n_dft(float signal[], float spec_real[], float spec_imag[], float spec_magn[], int N, char* win_type){
    float* window = NULL;
	float* windowed = NULL;

	window = get_window(win_type, N);
	windowed = windowing(signal, window, N);

	for(int k = 0; k < N; k++){
		spec_real[k] = 0.0;
		spec_imag[k] = 0.0;

		for(int n = 0; n < N; n++){
			spec_real[k] += signal[n] * cos(2 * PI * k * n / N);
			spec_imag[k] -= signal[n] * sin(2 * PI * k * n / N);
		}
		spec_magn[k] = sqrt(pow(spec_real[k], 2) + pow(spec_imag[k], 2));
	}

	free(window);

	return;
}


int argmax_magn(float spec_magn[], int N){
	float max_magn = 0.0;
	int argmax = 0;

	for(int k = 0; k < N; k++){
		if(max_magn < spec_magn[k]){
			max_magn = spec_magn[k];
			argmax = k;
		}
	}

	return argmax;
}