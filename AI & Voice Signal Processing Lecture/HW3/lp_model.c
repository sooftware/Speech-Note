#include "signal.h"

#define N_DFT 320
#define STRIDE 10
#define SHORT_SIZE 2
#define N_READ 1
#define WINDOW_TYPE "hamming"


int main(void) {
	FILE *fin, *ffc, *fde, *fenv;
	double* signal = float_zeros(N_DFT);
	double* window = float_zeros(N_DFT);
	double* errors = float_zeros(STRIDE + 1);
	double* reflect_coef = float_zeros(STRIDE + 1);
	double** filter_coef = (double**)malloc(sizeof(double*) * (STRIDE + 1));
	double *corrs, *transfer_func, *envelope, *spec_magn;
	short data[STRIDE];

	for (int i = 0; i <= STRIDE; i++)
		filter_coef[i] = float_zeros(STRIDE + 1);

	fopen_s(&fin, "Male.raw", "rb");
	fopen_s(&ffc, "filter_coef.txt", "wb");
	fopen_s(&fde, "durbin_error.txt", "wb");
	fopen_s(&fenv, "envelope.txt", "wb");

	for (int i = 0; i < N_DFT; i++) {
		fread(data, SHORT_SIZE, N_READ, fin);
		signal[i] = (double) * data; 
	}

	window = get_window(WINDOW_TYPE, N_DFT);
	signal = windowing(signal, window, N_DFT);
	signal = masking(signal, 0, 160, N_DFT);

	corrs = get_auto_corr(signal, N_DFT, STRIDE);
	durbin_algorithm(corrs, errors, reflect_coef, filter_coef, STRIDE);

	transfer_func = get_transfer_func(filter_coef, N_DFT, STRIDE);
	spec_magn = dft(transfer_func, N_DFT);
	envelope = inverse(spec_magn, N_DFT);


	for (int i = 1; i <= STRIDE; i++) {
		fprintf(ffc, "%10.7f\n", filter_coef[STRIDE][i]);
		fprintf(fde, "%10.7f\n", errors[i]);
	}

	for (int i = 0; i < N_DFT; i++)
		fprintf(fenv, "%10.7f\n", envelope[i]);

	free(envelope);
	free(errors);
	free(reflect_coef);
	free(window);
	free(signal);
	free(filter_coef);

	fclose(fin);
	fclose(ffc);
	fclose(fde);
	fclose(fenv);

	return 0;
}