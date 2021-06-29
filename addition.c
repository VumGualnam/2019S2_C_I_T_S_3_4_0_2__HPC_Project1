#include "headers.h"

void intaddition(int*row1, int*col1, int*val1, int*row2, int*col2, int*val2, FILE *fptr){
	for (int index1 = 0, index2 = 0; index1 < file1_totalNonzeros && index2 < file2_totalNonzeros;){
	omp_set_num_threads(input_num_threads);	
	#pragma omp parallel shared (index1, index2, file1_totalNonzeros, file2_totalNonzeros)
	#pragma omp single
	{
		
	// #pragma omp task shared(file1_numRows, file2_numRows, index1, index2,  file1_totalNonzeros, file2_totalNonzeros)
		{	
			// #pragma omp parallel shared(index1, index2, file1_totalNonzeros, file2_totalNonzeros)
			// {	
			// #pragma omp for
				for ( int i = 0; i < file1_numRows; i++){
				for(int j = 0 ; j < file2_numRows; j++){
					
			
			// for (int n = 0; n < file1_numRows*file2_numRows; n++){
				// int i = n/file2_numRows; int j = n % file2_numRows;
					// #pragma omp taskwait
					// #pragma omp task shared (i,j,index1, index2, file1_totalNonzeros, file2_totalNonzeros)
					#pragma omp critical
					if ( i == row1[index1] && i == row2[index2] && 
					     j == col1[index1] && j == col2[index2]){
						#pragma omp taskwait
						fprintf(fptr,"%d ", val1[index1] + val2[index2]);
						if(!required_logging) printf("%d ", val1[index1] + val2[index2]);
							
							index1++;
							index2++;
			
					} else if ( i == row1[index1] && j == col1[index1]){
						#pragma omp taskwait
						fprintf(fptr,"%d ", val1[index1]);
						if(!required_logging) printf("%d ", val1[index1]);
						index1++;
					} else if ( i == row2[index2] && j == col2[index2]){
						#pragma omp taskwait
						fprintf(fptr,"%d ", val2[index2]);	
						if(!required_logging) printf("%d ", val2[index2]);
						index2++;
					} else {
						#pragma omp taskwait
						fprintf(fptr,"%d ", 0);
						if (!required_logging) printf("%d ", 0);
					}
				}			
			}//}
		}}
	
	fprintf(fptr,"\n");
	if(!required_logging) printf("\n");
}
}

void floataddition(int*row1, int*col1, long double*val1, int*row2, int*col2, long double*val2, FILE *fptr){
	for (int index1 = 0, index2 = 0; index1 < file1_totalNonzeros && index2 < file2_totalNonzeros;){
		omp_set_num_threads(input_num_threads);
		#pragma omp parallel shared (index1, index2, file1_totalNonzeros, file2_totalNonzeros)
		{
			#pragma omp single
			for (int i = 0; i < file1_numRows; i++){
				for(int j = 0 ; j < file2_numRows; j++){
					
					#pragma omp critical
					if ( i == row1[index1] && i == row2[index2] && 
					     j == col1[index1] && j == col2[index2]){
						fprintf(fptr,"%.10Lg ", val1[index1] + val2[index2]);
						if(!required_logging) printf("%.10Lg ", val1[index1] + val2[index2]);
							index1++;
							index2++;
					#pragma omp taskwait		
					} else if ( i == row1[index1] && j == col1[index1]){
						fprintf(fptr,"%.10Lg ", val1[index1]);
						if(!required_logging) printf("%.10Lg ", val1[index1]);
						index1++;
					#pragma omp taskwait
					} else if ( i == row2[index2] && j == col2[index2]){
						fprintf(fptr,"%.10Lg ", val2[index2]);	
						if(!required_logging) printf("%.10Lg ", val2[index2]);	
						index2++;
					#pragma omp taskwait
					} else {
						fprintf(fptr,"%.1f ", 0.0);
						if(!required_logging) printf("%.1f ", 0.0);
					}
				}			
			}	
		}
	}
		fprintf(fptr,"\n");
		if(!required_logging) printf("\n");

}
