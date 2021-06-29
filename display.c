#include "headers.h"

void displayingResults(){
	printf("Filename: %s\n",out_filename_function(operation_requested));
	printf("\n%s\n", operation_requested);
	printf("%s\n", file1_name);
	if (file2_exists) printf("%s\n", file2_name);
	if (thread) printf("%d\n", input_num_threads);
	
}