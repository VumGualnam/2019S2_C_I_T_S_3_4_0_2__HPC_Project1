#include "headers.h"

void freeMemory(){
	
	free(matrix1_rowindices);
	free(matrix1_colindices);
	free(matrix1_intvalues);
	free( matrix1_floatvalues);
	free(matrix1_nonzero_rowcount);
	
///////////////////////////

	free(matrix2_rowindices);
	free(matrix2_colindices);
	free(matrix2_intvalues);
	free(matrix2_floatvalues);
	free(matrix2_nonzero_rowcount);
	
	free(m1csc);
	free(m2csc);	
}