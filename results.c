#include "headers.h"

void printingResult_oneFileInfo(FILE *fptr);
void printingResult_twoFileInfo(FILE *fptr);

void results(FILE* fptr){
	if (sm){
		printingResult_oneFileInfo(fptr);
		if(file_inttype){
			intsm(matrix1_rowindices, matrix1_colindices, 
					matrix1_intvalues, file1_totalNonzeros,
					fptr, file1_numRows, file1_numCols);
		} 
		if(file_floattype){
			floatsm(matrix1_rowindices, matrix1_colindices, 
					matrix1_floatvalues, file1_totalNonzeros, 
					fptr, file1_numRows, file1_numCols);
		}
	} else if (tr) {
		intfloattrace();
		if (file_inttype){
			fprintf(fptr, "%d\n", inttrace_val);
			printf("%d\n", inttrace_val);
		} else {
			fprintf(fptr, "%.10Lg\n", floattrace_val);
			printf("%.10Lg\n", floattrace_val);
		}
	} else if (ad) {
		printingResult_twoFileInfo(fptr);
		
		if (file_inttype){ 
			intaddition(matrix1_rowindices, matrix1_colindices, 
						matrix1_intvalues, matrix2_rowindices, 
						matrix2_colindices, matrix2_intvalues, fptr);
		} else {
			floataddition(matrix1_rowindices, matrix1_colindices, 
						matrix1_floatvalues, matrix2_rowindices, 
						matrix2_colindices, matrix2_floatvalues, fptr);	
		}
		
		
	} else if (ts) {
		printingResult_oneFileInfo(fptr);
		
		qsort(m1csc, file1_totalNonzeros, sizeof(struct csc), comparator1);
		
		if (file_inttype){
			int_transpose(file1_totalNonzeros, fptr, file1_numCols, file1_numRows);
		} else {
			float_transpose(file1_totalNonzeros, fptr, file1_numCols, file1_numRows);
		}
	} else if (mm) {
		printingResult_twoFileInfo(fptr);
		multiplier(fptr);
		
		
	}
}

void printingResult_oneFileInfo(FILE *fptr){
	if(file_inttype) {
		fprintf(fptr, "int\n");
		printf("int\n");
	}else if(file_floattype) {
			fprintf(fptr, "float\n");
			printf("float\n");
		}
	fprintf(fptr, "%d\n%d\n", file1_numRows, file1_numCols);
	printf("%d\n%d\n", file1_numRows, file1_numCols);
	if(required_logging) printf("Printing to output file...\n");
}

void printingResult_twoFileInfo(FILE *fptr){
	if(file_inttype) {
		fprintf(fptr, "int\n");
		printf("int\n");
	}else if(file_floattype) {
			fprintf(fptr, "float\n");
			printf("float\n");
		}
	fprintf(fptr, "%d\n%d\n", file1_numRows, file2_numCols);
	printf("%d\n%d\n", file1_numRows, file2_numCols);
	if(required_logging) printf("Printing to output file...\n");
}

