#include "signal.h"

#define SHORT_SIZE 2
#define N_READ 1
#define N_DFT 320
#define PI 3.14
#define WINDOW_TYPE "hamming"
#define THRESHOLD 15


int main() {
	FILE *fin, *spectrum_fp, *low_freq_envelope_fp, *high_freq_envelope_fp, *low_filterred_fp;
	double* signal = float_zeros(N_DFT);
	double* window = float_zeros(N_DFT);
	double *spec, *spec_clone, *log_spec, *cepstrum, *low_filtered, *high_filtered;
	double *low_freq_envelope, *high_freq_envelope;
	short data[10];

	fopen_s(&fin, "Male.raw", "rb");
	fopen_s(&low_freq_envelope_fp, "low_freq_envelope.txt", "wb");
	fopen_s(&high_freq_envelope_fp, "high_freq_envelope.txt", "wb");
	fopen_s(&spectrum_fp, "spectrum.txt", "wb");
	fopen_s(&low_filterred_fp, "low_filterred.txt", "wb");

	for (int i = 0; i < N_DFT; i++) {
		fread(data, SHORT_SIZE, N_READ, fin);
		signal[i] = (double)* data;
	}

	window = get_window(WINDOW_TYPE, N_DFT);
	signal = windowing(signal, window, N_DFT);

	spec = dft(signal, N_DFT);
	log_spec = get_log(spec, N_DFT);
	cepstrum = idft(log_spec, N_DFT);

	low_filtered = lowpass_filter(cepstrum, N_DFT, THRESHOLD);
	high_filtered = highpass_filter(cepstrum, N_DFT, THRESHOLD);

	low_freq_envelope = dft(low_filtered, N_DFT);
	high_freq_envelope = dft(high_filtered, N_DFT);

	for (int i = 0; i < N_DFT; i++)
		fprintf(low_freq_envelope_fp, "%10.7f\n", low_freq_envelope[i]);

	for (int i = 0; i < N_DFT; i++)
		fprintf(high_freq_envelope_fp, "%10.7f\n", high_freq_envelope[i]);

	for (int i = 0; i < N_DFT; i++)
		fprintf(spectrum_fp, "%10.7f\n", spec[i]);

	for (int i = 0; i < N_DFT; i++)
		fprintf(low_filterred_fp, "%10.7f\n", low_filtered[i]);


	// File close
	fclose(fin);
	fclose(low_freq_envelope_fp);
	fclose(high_freq_envelope_fp);
	fclose(spectrum_fp);
	fclose(low_filterred_fp);

	return 0;
}
