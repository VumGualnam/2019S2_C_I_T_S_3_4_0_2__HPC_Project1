#include "headers.h"


void fileprocessor(){
	getfile1Info();
	if(tr) checkfor_tracibility();
	
	if(file2_exists) getfile2Info();
	
	if (ad) checkfor_Additibility();
	if (mm) checkfor_Multiplicability();
	
	matrix1Converter();
	
	if(file2_exists) {
		matrix2Converter();
	}
}

void checkfor_Additibility(){
	if(file1_numRows != file2_numRows || file1_numCols != file2_numCols) {
			printf("Unable to do addition: Number of Rows/Columns are different!!!\n");
			exit(1);
		}
}

void checkfor_Multiplicability(){
	if (file1_numCols != file2_numRows) {
		printf("Unable to do multiplication: Number of Column of 1st Matrix is not equal to number of Row of 2nd Matrix!!!\n");
		exit(2);
	} 
}