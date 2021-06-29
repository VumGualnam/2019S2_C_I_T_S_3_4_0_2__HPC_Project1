#include "headers.h"


void truncateNrounding(long double num, FILE *fp);

void multiplier(FILE *fp){
	// omp_set_num_threads(input_num_threads);
	qsort(m2csc, file2_totalNonzeros, sizeof(struct csc2), comparator2); // sorting csr column_wise	

	struct csc2 * b = m2csc;
	// /***
	int* aRow = matrix1_rowindices;
	int* aCol = matrix1_colindices;
	int* aintVal = matrix1_intvalues;
	long double *afloatVal = matrix1_floatvalues;
	
	
	
	// #pragma omp parallel shared(aRow, aCol, aintVal, afloatVal) //for collapse(2)
	{
		// for (int i = 0; i < f1nnz; i++){
			// for (int j = 0; j < f2nnz; j++){
		{for (int i = 0; i < file1_numRows; i++){
			for (int j = 0; j < file2_numCols; j++){
				// #pragma omp single
				{

					{int intVal_ij = 0;
					long double floatVal_ij = 0.0;
					
					// #pragma omp parallel for schedule(guided) reduction(+:intVal_ij, floatVal_ij)
					// #pragma omp for schedule(static, input_num_threads)
					for (int m = 0; m < file1_totalNonzeros; m++){
						for (int n = 0; n < file2_totalNonzeros; n++){
							// #pragma omp task
							// #pragma omp critical
							{
								if (aRow[m] ==  i && (b+n)->colind == j){
									if (aCol[m] == (b+n)->rowind) {
									if(file_inttype) intVal_ij += aintVal[m] * (b+n)->intval;
									if(file_floattype) floatVal_ij += afloatVal[m] * (b+n)->floatval;
									// printf("intVal_ij = %d\n", intVal_ij);
									}
								}
							}
							
						}
					}				
					// #pragma omp taskwait
					// #pragma omp single
					
					{
						if (file_inttype) fprintf(fp, "%d ", intVal_ij);
						if(file_inttype && !required_logging) printf("%d ", intVal_ij);
						if (file_floattype){
							if (floatVal_ij == 0.0){
								fprintf(fp, "%d. ", 0);
								if(!required_logging) printf("%d. ", 0);
							} else {
								truncateNrounding(floatVal_ij, fp);
								// fprintf(fp, "%*.*Lg ", 0,12, floatVal_ij);
							}
						}
					
					}
				}}
			}
		}
	}}
	fprintf(fp, "\n");
	if(!required_logging) printf("\n");
}	

void truncateNrounding(long double num, FILE *fp) {
	char str[50];
	int sz; long double d2;

    // Allow for negative.
    d2 = (num >= 0) ? num : -num;
    sz = (num >= 0) ? 0 : 1;

    // Add one for each whole digit (0.xx special case).
    if (d2 < 1) sz++;
    while (d2 >= 1) { d2 /= 10.0; sz++; }

    // Adjust for decimal point and fractionals.
    sz += 1 + 6;

    // Create format string then use it.
    sprintf (str, "%*.*Lf", sz, 6, num);
	int count;
	char * p = strchr (str,'.');         // Find decimal point, if any.
    if (p != NULL) {
        count = 6;              // Adjust for more or less decimals.
        while (count >= 0) {    // Maximum decimals allowed.
             count--;
             if (*p == '\0')    // If there's less than desired.
                 break;
             p++;               // Next character.
        }

        *p-- = '\0';            // Truncate string.
        while (*p == '0')       // Remove trailing zeros.
            *p-- = '\0';
	
        // if (*p == '.') {        // If all decimals were zeros, remove ".".
            // *p = '\0';
        // }
	}
	fprintf(fp, "%s ", str);
	if(!required_logging) printf("%s ", str);
}