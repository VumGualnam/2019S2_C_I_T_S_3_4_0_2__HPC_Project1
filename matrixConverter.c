#include "headers.h"


int* matrix1_rowindices;
int* matrix1_colindices;
int* matrix1_intvalues;
long double* matrix1_floatvalues;
int* matrix1_nonzero_rowcount;
//////////////////////////////////////////
int* matrix2_rowindices;
int* matrix2_colindices;
int* matrix2_intvalues;
long double* matrix2_floatvalues;
int* matrix2_nonzero_rowcount; // for CSR

struct timeval m1startConversion, m1endConversion, m2startConversion, m2endConversion;
float m1timeConversion = 0;
float m2timeConversion = 0;

void matrix1Converter(){
	
	gettimeofday(&m1startConversion, NULL);
	
		FILE *fptr = fopen(file1_name, "r");
		if (fptr == NULL)
		{
			printf("matrix1Converter: Error opening file 1\n");
			exit(1);
		}
		char* buff;
		buff = (char*)malloc(1*sizeof(char));
		
	int i = 0; // file iterator
	
	int file_rowindex = 0;
	int file_colindex = 0;
	int file_numCols = file1_numCols;
	int common_index = 0; // for storing row, col and values
	int nonzero_rowcount = 0; // for CSR
	
	matrix1_rowindices = (int*)malloc(1*sizeof(int));
	matrix1_colindices = (int*)malloc(1*sizeof(int));
	if (file_inttype) matrix1_intvalues = (int*)malloc(1*sizeof(int));
	if (file_floattype) matrix1_floatvalues = (long double*)malloc(1*sizeof(long double));
	
	matrix1_nonzero_rowcount = (int*)malloc(1*sizeof(int));
	matrix1_nonzero_rowcount[0] = 0;
	
	m1csc = (struct csc *) malloc(1* sizeof(struct csc));
	
	
	while((fscanf(fptr, "%s", buff)!= EOF)){
		buff = realloc(buff, (i+1)*sizeof(char));

		if ( i == 0 ) {	
			i++;
			continue;
		} else if (i ==1 ) {
			i++;
			continue;
		} else if(i == 2) {
			i++;
			continue;
		}
		else if (atof(buff) != 0.0) {			
			
			matrix1_rowindices = (int*)realloc(matrix1_rowindices, (common_index+1)*sizeof(int));
			matrix1_colindices = (int*)realloc(matrix1_colindices, (common_index+1)*sizeof(int));
			if (file_inttype) matrix1_intvalues = (int*)realloc(
					matrix1_intvalues, (common_index+1)*sizeof(int)
					);
			if (file_floattype) matrix1_floatvalues = (long double*)realloc(
					matrix1_floatvalues, (common_index+1)*sizeof(long double)
					);
			
			m1csc = (struct csc *)realloc (m1csc, (common_index+1)* sizeof(struct csc));
			(m1csc+common_index)->rowind = file_rowindex;
			(m1csc+common_index)->colind = file_colindex;
			if (file_inttype) (m1csc+common_index)->intval = atoi(buff);
			if (file_floattype) (m1csc+common_index)->floatval = strtod(buff, NULL);
			
			matrix1_rowindices[common_index] = file_rowindex;
			matrix1_colindices[common_index] = file_colindex;
			if (file_inttype) matrix1_intvalues[common_index] = atoi(buff);
			if (file_floattype) matrix1_floatvalues[common_index] = strtod(buff, NULL);
			
			common_index++;
			nonzero_rowcount++; // for CSR
			
			if (file_colindex == file_numCols - 1){
				file_colindex = 0;
				file_rowindex += 1;
				
				matrix1_nonzero_rowcount = (int*)realloc(
						matrix1_nonzero_rowcount, (file_rowindex+1)*sizeof(int)
						);
				matrix1_nonzero_rowcount[file_rowindex] = nonzero_rowcount;
				
			}		
			else{
				file_colindex++;
			}	
		}	
		else if (atof(buff) == 0.0){
			if (file_colindex == file_numCols - 1){
				file_colindex = 0;
				file_rowindex += 1;
			} else {
				file_colindex++;
			}	
		}	
	
	i++; // file iterator		
	
	}
	fclose(fptr);
	
	gettimeofday(&m1endConversion, NULL);
	m1timeConversion = ((m1endConversion.tv_sec - m1startConversion.tv_sec) * 1000000u +
							m1endConversion.tv_usec - m1startConversion.tv_usec) / 1.e6;
}

void matrix2Converter(){
	gettimeofday(&m2startConversion, NULL);
	
		FILE *fptr = fopen(file2_name, "r");
		if (fptr == NULL)
		{
			printf("matrix2Converter: Error opening file 2\n");
			exit(1);
		}
		char* buff;
		buff = (char*)malloc(1*sizeof(char));
		
	int i = 0; // file iterator
	
	int file_rowindex = 0;
	int file_colindex = 0;
	int file_numCols = file2_numCols;
	int common_index = 0; // for storing row, col and values
	int nonzero_rowcount = 0; // for CSR
	
	matrix2_rowindices = (int*)malloc(1*sizeof(int));
	matrix2_colindices = (int*)malloc(1*sizeof(int));
	if (file_inttype) matrix2_intvalues = (int*)malloc(1*sizeof(int));
	if (file_floattype) matrix2_floatvalues = (long double*)malloc(1*sizeof(long double));
	
	m2csc = (struct csc2 *) malloc(1* sizeof(struct csc2));
	
	// CSRmatrix2_nonzero_rowcount = (int*)malloc(1*sizeof(int));
	// CSRmatrix2_nonzero_rowcount[0] = 0; 
	
	while((fscanf(fptr, "%s", buff)!= EOF)){
		buff = realloc(buff, (i+1)*sizeof(char));

		if ( i == 0 ) {	
			i++;
			continue;
		} else if (i ==1 ) {
			i++;
			continue;
		} else if(i == 2) {
			i++;
			continue;
		}
		else if (atof(buff) != 0.0) {
			
			matrix2_rowindices = (int*)realloc(matrix2_rowindices, (common_index+1)*sizeof(int));
			matrix2_colindices = (int*)realloc(matrix2_colindices, (common_index+1)*sizeof(int));
			if (file_inttype) matrix2_intvalues = (int*)realloc(
					matrix2_intvalues, (common_index+1)*sizeof(int)
					);
			if (file_floattype) matrix2_floatvalues = (long double*)realloc(
					matrix2_floatvalues, (common_index+1)*sizeof(long double)
					);
			
			m2csc = (struct csc2 *)realloc (m2csc, (common_index+1)* sizeof(struct csc2));
			(m2csc+common_index)->rowind = file_rowindex;
			(m2csc+common_index)->colind = file_colindex;
			if (file_inttype) (m2csc+common_index)->intval = atoi(buff);
			if (file_floattype) (m2csc+common_index)->floatval = strtod(buff, NULL);
			
			matrix2_rowindices[common_index] = file_rowindex;
			matrix2_colindices[common_index] = file_colindex;
			if (file_inttype) matrix2_intvalues[common_index] = atoi(buff);
			if (file_floattype) matrix2_floatvalues[common_index] = strtod(buff, NULL);
			
			common_index++;
			nonzero_rowcount++; // for CSR
			
			if (file_colindex == file_numCols - 1){
				file_colindex = 0;
				file_rowindex += 1;
			}		
			else{
				file_colindex++;
			}	
		}	
		else if (atof(buff) == 0.0){
			if (file_colindex == file_numCols - 1){
				file_colindex = 0;
				file_rowindex += 1;
			} else {
				file_colindex++;
			}	
		}	
	i++; // file iterator		
	}
	fclose(fptr);
	gettimeofday(&m2endConversion, NULL);
	m2timeConversion = ((m2endConversion.tv_sec  - m2startConversion.tv_sec) * 1000000u +
							m2endConversion.tv_usec - m2startConversion.tv_usec) / 1.e6;
}