#include <stdio.h>
#include <stdlib.h>

#define DIM 10
#define N_EPOCHS 1
#define PRINT_EVERY 500
#define random() (((float)rand() / RAND_MAX) - 0.5)


void supervised_train(float* weight, float lr);
void save_result(FILE *fout, float *weight, float loss);
void read_data(FILE *fin, float *input, float *target);
float forward(float *input, float *weight);
float* backprop(float *weight, float *input, float error, float lr);
void init_weight(float *weight);


int main() {
	float *weight = (float*)malloc(sizeof(float) * DIM);
	float lr = 0.1;
	
	init_weight(weight, lr);

	for (int epoch = 0; epoch < N_EPOCHS; epoch++)
		supervised_train(weight, lr);

	return 0;
}


void supervised_train(float* weight, float lr) {
	FILE *fin, *fout;
	float *input = (float*)malloc(sizeof(float) * DIM);
	float target = 0.0;
	float hypothesis = 0.0;
	float loss = 0.0;
	float error = 0.0;

	fopen_s(&fin, "trainingDB.dat", "rt");
	fopen_s(&fout, "output.dat", "wt");

	for (int timestep = 0; !feof(fin); timestep++) {
		read_data(fin, input, &target);

		hypothesis = forward(input, weight);

		error = hypothesis - target;
		loss = ((error * error) / 2);

		backprop(weight, input, error, lr);

		save_result(fout, weight, loss);

		if (timestep % PRINT_EVERY == 0.0)
			printf("%10.7f\n", loss);
	}

	fclose(fin);
	fclose(fout);
}


void save_result(FILE *fout, float *weight, float loss) {
	for (int i = 0; i < DIM; i++)
		fprintf(fout, "%10.7f ", weight[i]);
	fprintf(fout, "%10.7f\n", loss);

	return;
}


void read_data(FILE *fin, float *input, float *target) {
	for (int i = 0; i < DIM; i++)
		fscanf_s(fin, "%f", input + i);

	fscanf_s(fin, "%f", target);

	return;
}


float forward(float *input, float *weight) {
	float hypothesis = 0.0;

	for (int i = 0; i < DIM; i++)
		hypothesis += input[i] * weight[i];

	return hypothesis;
}


float* backprop(float *weight, float *input, float error, float lr) {
	for (int i = 0; i < DIM; i++)
		weight[i] -= (lr * input[i] * error);

	return weight;
}


void init_weight(float *weight) {
	for (int i = 0; i < DIM; i++)
		weight[i] = random();

	return;
}
