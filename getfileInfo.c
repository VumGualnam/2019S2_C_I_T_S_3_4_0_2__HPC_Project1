#include "headers.h"

bool file_floattype = false;
bool file_inttype = false;

int file1_numRows = 0;
int file1_numCols = 0;
int file1_totalNonzeros = 0;

int file2_numRows = 0;
int file2_numCols = 0;
int file2_totalNonzeros = 0;

int checkfor_tracibility(){
	if(file1_numRows != file1_numCols) {
		printf("Trace is undefined\n");
		exit(3);
	}
	return 0;
}

int getfile1Info(){
	
	FILE *fptr = fopen(file1_name, "r");
	if (fptr == NULL)
	{
		printf("\nGetfile1Info: Error opening file 1\n");
		exit(1);
	}
	char* buff;
	buff = (char*)malloc(1*sizeof(char));
	int i = 0;
		
	while((fscanf(fptr, "%s", buff)!= EOF))
	{
		// buff = realloc(buff, (i+1)*sizeof(char));

		if ( i == 0)
		{
			if (strcmp(buff,"float") == 0) {
				file_floattype = true;
			}else { 
				file_inttype = true;
			}
		}
		else if (i == 1)
		{
			file1_numRows = atoi(buff);
		}
		else if (i == 2)
		{
			file1_numCols = atoi(buff);
		} 
		else if (atof(buff) != 0.0) 
		{
		file1_totalNonzeros++;
		}
		
	i++;	
	}	
	fclose(fptr);
	// free(buff);
	return 0;
}
	
int getfile2Info(){
	FILE *fptr = fopen(file2_name, "r");
	if (fptr == NULL)
	{
		printf("\nGetfile2Info: Error opening file 2\n");
		exit(1);
	}
	char* buff;
	buff = (char*)malloc(1*sizeof(char));
	int i = 0;
		
	while((fscanf(fptr, "%s", buff)!= EOF))
	{
		// buff = realloc(buff, (i+1)*sizeof(char));

		if ( i == 0)
		{
			if (strcmp(buff,"float") == 0) {
				file_floattype = true;
			}else { 
				file_inttype = true;
			}
		}
		else if (i == 1)
		{
			file2_numRows = atoi(buff);
		}
		else if (i == 2)
		{
			file2_numCols = atoi(buff);
		} 
		else if (atof(buff) != 0.0) 
		{
		file2_totalNonzeros++;
		}
		
	i++;	
	}	
	fclose(fptr);
	// free(buff);
	return 0;
}	