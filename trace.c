#include "headers.h"


int inttrace_val = 0;
long double floattrace_val = 0.0;


/* Function to calculate trace of a matrix */

void intfloattrace(){
	// omp_set_num_threads(input_num_threads);
	if(required_logging) printf("Printing to output file...\n");
	if (file_inttype){
		// #pragma omp parallel for shared(file1_totalNonzeros) reduction(+: inttrace_val) //num_threads(input_num_threads)
		#pragma omp parallel for reduction(+: inttrace_val)
		for(int i = 0; i < file1_totalNonzeros; i++){
			if (matrix1_rowindices[i] == matrix1_colindices[i]){
				// #pragma omp critical
					inttrace_val += matrix1_intvalues[i];
		}
		// fprintf(fp, "%d\n", inttrace_val);
		// printf("%d\n", inttrace_val);
	}
	} else if(file_floattype){
		// omp_set_num_threads(input_num_threads);
		// #pragma omp parallel for shared(file1_totalNonzeros) reduction(+: floattrace_val) //num_threads(input_num_threads)
		#pragma omp parallel for reduction(+: floattrace_val)
		for(int i = 0; i < file1_totalNonzeros; i++){
			if (matrix1_rowindices[i] == matrix1_colindices[i]){
				// #pragma omp critical
					floattrace_val += matrix1_floatvalues[i];
			}
		}
		// fprintf(fp, "%f\n", floattrace_val);
		// printf("%f\n", floattrace_val);
		
	}
}