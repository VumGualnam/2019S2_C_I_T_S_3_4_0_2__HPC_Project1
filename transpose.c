#include "headers.h"


/* Function to transpose integer matrix */
void int_transpose(int num_nonzeros, FILE* fptr, int num_row, int num_col){
	struct csc *m1 = m1csc;
	// omp_set_num_threads(input_num_threads);
		
	for (int common_index = 0; common_index < num_nonzeros; common_index++){
		#pragma omp task shared(common_index) 
		{
			for (int i = 0; i < num_row; i++){
				for(int j = 0 ; j < num_col; j++){
				// #pragma omp taskwait
					#pragma omp critical
					if(i == (m1+common_index)->colind && j == (m1+common_index)->rowind){
						fprintf(fptr,"%d ", (m1+common_index)->intval);
						if(!required_logging) printf("%d ", (m1+common_index)->intval);
						common_index++;
					} else {
						fprintf(fptr,"%d ", 0);
						if(!required_logging) printf("%d ", 0);
					}
				}			
			}
		}
	}
	fprintf(fptr,"\n");
	if(!required_logging) printf("\n");
}



/* Function to transpose float matrix */
void float_transpose(int num_nonzeros, FILE* fptr, int num_row, int num_col){
	struct csc *m1 = m1csc;
		
	for (int common_index = 0; common_index < num_nonzeros; common_index++){
		#pragma omp task shared(common_index) 
		{
			for (int i = 0; i < num_row; i++){
				for(int j = 0 ; j < num_col; j++){
					#pragma omp taskwait
					// #pragma omp critical
					if(i == (m1+common_index)->colind && j == (m1+common_index)->rowind){
						fprintf(fptr,"%.10Lg ", (m1+common_index)->floatval);
						if(!required_logging) printf("%.10Lg ", (m1+common_index)->floatval);
							common_index++;
					} else {
						fprintf(fptr,"%d. ", 0);
						if(!required_logging)printf("%d. ", 0);
						
					}
				}			
			}
		}	
	}
	fprintf(fptr,"\n");
	if(!required_logging) printf("\n");
}