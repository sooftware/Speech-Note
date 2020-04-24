/*
  	code made by Soohwan Kim

	- resume: https://sooftware.github.io/
	- github profile: https://github.com/sooftware
	- naver blog: https://blog.naver.com/sooftware
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SHORT_SIZE 	2
#define PI 			3.14

float* get_window(char* win_type, int window_size);
float* windowing(float* signal, float* window, int window_size);
float convert_hertz(int k, int sr, int N_POINT);
int dft(float signal[], float spec_real[], float spec_imag[], float spec_magn[], int N_POINT, char* win_type);
int argmax_magnitude(float spec_magn[], int N_POINT);


float* get_window(char* win_type, int window_size) {
	float* window = (float*)malloc(sizeof(float) * window_size);

	if (!strcmp(win_type, "hamming")) {
		for (int n = 0; n < window_size; n++)
			window[n] = 0.54 - 0.46 * cos(2 * PI * n / (window_size - 1));
	}
	else if (!strcmp(win_type, "hanning")) {
		for (int n = 0; n < window_size; n++)
			window[n] = 0.5 - 0.5 * cos(2 * PI * n / (window_size - 1));
	}
	else if (!strcmp(win_type, "rectangular")) {
		for (int n = 0; n < window_size; n++)
			window[n] = 1.0;
	}
	else if (!strcmp(win_type, "blackman")) {
		for (int n = 0; n < window_size; n++)
			window[n] = 0.42 - 0.5 * cos(2 * PI * n / (window_size - 1)) + 0.08 * cos(4 * PI * n / (window_size - 1));
	}
	else if (!strcmp(win_type, "sine")) {
		for (int n = 0; n < window_size; n++)
			window[n] = sin(PI * (n + 0.5) / window_size);
	}
	else {
		printf("%s is not Supported\n", win_type);
	}

	return window;
}


float* windowing(float* signal, float* window, int window_size) {
	for (int n = 0; n < window_size; n++)
		signal[n] *= window[n];

	return signal;
}


int dft(float signal[], float spec_real[], float spec_imag[], float spec_magn[], int N_POINT, char* win_type) {
	float* window = NULL;
	float* windowed = NULL;

	window = get_window(win_type, N_POINT);
	windowed = windowing(signal, window, N_POINT);

	for (int k = 0; k < N_POINT; k++) {
		spec_real[k] = 0.0;
		spec_imag[k] = 0.0;

		for (int n = 0; n < N_POINT; n++) {
			spec_real[k] += signal[n] * cos(2 * PI * k * n / N_POINT);
			spec_imag[k] -= signal[n] * sin(2 * PI * k * n / N_POINT);
		}
		spec_magn[k] = pow(spec_real[k], 2) + pow(spec_imag[k], 2);
		spec_magn[k] = sqrt(spec_magn[k]);
	}

	free(window);
	return 0;
}


int argmax_magnitude(float spec_magn[], int N_POINT) {
	float max_magn = 0.0;
	int argmax = 0;

	for (int k = 0; k < N_POINT; k++) {
		if (max_magn < spec_magn[k]) {
			max_magn = spec_magn[k];
			argmax = k;
		}
	}

	return argmax;
}


float convert_hertz(int k, int sr, int N_POINT) {
	float spec_resolution = (float)sr / (float)N_POINT;

	return (float)k * spec_resolution;
}


