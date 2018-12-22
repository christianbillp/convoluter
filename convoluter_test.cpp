#include <stdio.h>
#include <stdlib.h>

#define DATA_ROWS 28
#define DATA_COLUMNS 28
#define DATA_VALUE 1
#define KERNEL_ROWS 3
#define KERNEL_COLUMNS 3
#define KERNEL_VALUE 1
#define KERNEL_SIZE (KERNEL_ROWS-1)/2
#define OUTPUT_ROWS DATA_ROWS-KERNEL_SIZE*2
#define OUTPUT_COLUMNS DATA_COLUMNS-KERNEL_SIZE*2

float data[DATA_ROWS][DATA_COLUMNS];
float kernel[KERNEL_ROWS][KERNEL_COLUMNS];
float output[OUTPUT_ROWS][OUTPUT_COLUMNS];

int set_data(float data[DATA_ROWS][DATA_COLUMNS]) {
	for (int row = 0; row < DATA_ROWS; row++) {
		for (int column = 0; column < DATA_COLUMNS; column++) {
			data[row][column] = DATA_VALUE;
		}
	}
}

int set_kernel(float kernel[KERNEL_ROWS][KERNEL_COLUMNS]) {
	for (int row = 0; row < KERNEL_ROWS; row++) {
		for (int column = 0; column < KERNEL_COLUMNS; column++) {
			kernel[row][column] = KERNEL_VALUE;
		}
	}
}

int convolute(float image[DATA_ROWS][DATA_COLUMNS], float kernel[KERNEL_ROWS][KERNEL_COLUMNS]) {
	for (int row = 0; row < DATA_ROWS; row++) {
		for (int column = 0; column < DATA_COLUMNS; column++) {
			float total = 0;
			for (int kernel_row = 0; kernel_row < KERNEL_ROWS; kernel_row++) {
				for (int kernel_column = 0; kernel_column < KERNEL_COLUMNS; kernel_column++) {
					total += image[row+kernel_row][column+kernel_column] * kernel[kernel_row][kernel_column];
				}
			}
			output[row][column] = total;
		}
	}
}

int show_data(float data[DATA_ROWS][DATA_COLUMNS]) {
	printf("Data:\n");
	for (int row = 0; row < DATA_ROWS; row++ ) {
			for (int column = 0; column < DATA_COLUMNS; column++ ) {
				printf("%.2f ", data[row][column]);
			}
			printf("\n");
	}
}

int show_kernel(float kernel[KERNEL_ROWS][KERNEL_COLUMNS]) {
	printf("Kernel:\n");
	for (int row = 0; row < KERNEL_ROWS; row++) {
		for (int column = 0; column < KERNEL_COLUMNS; column++) {
				printf("%.2f ", kernel[row][column]);
			}
			printf("\n");
	}
}

int show_output(float output[OUTPUT_ROWS][OUTPUT_COLUMNS]) {
	printf("Output:\n");
	for (int row = 0; row < OUTPUT_ROWS; row++) {
		for (int column = 0; column < OUTPUT_COLUMNS; column++) {
				printf("%.2f ", output[row][column]);
			}
			printf("\n");
	}
}

void load_data(void) {
	FILE *myFile;
	myFile = fopen("mnist_example.csv", "r");

	for (int row = 0; row < DATA_ROWS; row++) {
		for (int column = 0; column < DATA_COLUMNS; column++) {
			fscanf(myFile, "%f,", &data[row][column] );
		}
	}
}

int check_data(float data[DATA_ROWS][DATA_COLUMNS]) {
	printf("Diagonal:\n");
	for (int row = 0; row < DATA_ROWS; row++ ) {
			for (int column = 0; column < DATA_COLUMNS; column++ ) {
				if (row == column) {
					printf("%.2f ", data[row][column]);
				}

			}
	}
	printf("\n");
}

int check_output(float output[OUTPUT_ROWS][OUTPUT_COLUMNS]) {
	printf("Output:\n");
	for (int row = 0; row < OUTPUT_ROWS; row++) {
		for (int column = 0; column < OUTPUT_COLUMNS; column++) {
				if (row == column) {
					printf("%.2f ", output[row][column]);
				}

			}
	}
	printf("\n");
}

int main() {
	/*set_data(data);
	show_data(data);
	set_kernel(kernel);
	show_kernel(kernel);
	convolute(data, kernel);
	show_output(output);

	// Load MNIST example image
	load_data();

	// Show diagonal
	check_data(data);

	// Set kernel values
	set_kernel(kernel);

	// Perform convolution
	convolute(data, kernel);

	// Present output diagonal
	check_output(output);
	 */

	return 0;
}

