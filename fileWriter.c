#include "headers.h"

struct timeval start, end;
FILE * fp;

void printingOutput(){
	
	fp = fopen (out_filename_function(operation_requested),"w");
	
	fprintf(fp, "%s\n%s\n", operation_requested, file1_name);
	if (file2_exists) fprintf(fp, "%s\n", file2_name);
	if (thread) fprintf(fp, "%d\n", input_num_threads);
	
	gettimeofday(&start, NULL);
	results(fp);
	gettimeofday(&end, NULL);
	
	float excecutionTime = ((end.tv_sec  - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1.e6);
	
	fprintf(fp, "%0.6f\n%0.6f\n", m1timeConversion + m2timeConversion, excecutionTime);
	
	printf("%0.6f\n%0.6f\n", m1timeConversion + m2timeConversion, excecutionTime);
	
	// printf("fileWriter: The time to load in & convert matrix file(s): %12.6f seconds\n", m1timeConversion+m2timeConversion);
	// printf("fileWriter: The time to execute the requested operation : %12.6f seconds\n", excecutionTime);
	
	
	fclose (fp);
}