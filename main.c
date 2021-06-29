



#include "headers.h"


int main (int argc, char **argv)
{
	parse_command_line(argc, argv); // Parse the command line 
	
	fileprocessor();
	printf("main: file1Nonzeros: %d\nfile2Nonzeros: %d\n", file1_totalNonzeros, file2_totalNonzeros);
	displayingResults();
	printingOutput(); // log to file if required
	
	freeMemory();
	
	return 0;
}
	