#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <getopt.h>
#include <time.h>
#include <sys/time.h>
#include <wchar.h>
#include <stdbool.h>


#define F1size 30
#define F2size 30
#define Flagsize 3
#define OUTPUT_FILENAME_SIZE 29
// variables from main.c


//variables from parser.c
extern int parse_command_line(int argc, char **argv);
extern char operation_requested[Flagsize];
extern char file1_name[F1size];
extern char file2_name[F2size];

extern bool file2_exists;

extern bool sm;
extern bool tr;
extern bool ad;
extern bool ts;
extern bool mm;
extern float input_scalar;
extern bool thread;

extern bool required_logging;
extern int input_num_threads;

//variables from trace.c
extern void intfloattrace();
extern int inttrace_val;
extern long double floattrace_val;

//variables from out_filename.c
extern char* out_filename_function(char* operation_req);
extern char out_filename[OUTPUT_FILENAME_SIZE];

// variables from fileWriter.c
extern void printingOutput();
extern struct timeval start, end;

// variables from addition.c
extern void intaddition(int*row1, int*col1, 
						int*val1, int*row2, int*col2, 
						int*val2, FILE *fptr);
extern void floataddition(int*row1, int*col1, 
						long double*val1, int*row2, 
						int*col2, long double*val2, FILE *fptr);

// variables from getfileInfo.c
extern int getfile1Info();
extern int getfile2Info();
extern int checkfor_tracibility();

extern bool file_floattype;
extern bool file_inttype;

// variables from fileprocessor.c
extern void fileprocessor();
extern void checkfor_Additibility();
extern void checkfor_Multiplicability();

extern int file1_numRows;
extern int file1_numCols;
extern int file1_totalNonzeros;

extern int file2_numRows;
extern int file2_numCols;
extern int file2_totalNonzeros;

// variables from results.c
extern void results(FILE* fptr);

// variables from display.c 
extern void displayingResults();

// variables from matrixConverter.c 

extern void matrix1Converter();
extern void matrix2Converter();

extern float m1timeConversion;
extern float m2timeConversion;

extern int* matrix1_rowindices;
extern int* matrix1_colindices;
extern int* matrix1_intvalues;
extern long double* matrix1_floatvalues;
extern int* matrix1_nonzero_rowcount;

//////////////////////////////////////////
extern int* matrix2_rowindices;
extern int* matrix2_colindices;
extern int* matrix2_intvalues;
extern long double* matrix2_floatvalues;
extern int* matrix2_nonzero_rowcount; // for CSR


// variables from scalarMul.c 
extern void intsm(int* row, int* col, int* val, 
					int num_nonzeros, FILE* fptr, 
					int num_row, int num_col);
extern void floatsm(int* row, int* col, 
					long double* val, int num_nonzeros, 
					FILE* fptr, int num_row, int num_col);

// variables from transpose.c
extern void int_transpose(int num_nonzeros, 
							FILE* fptr, int num_row, int num_col);
extern void float_transpose(int num_nonzeros, 
								FILE* fptr, int num_row, int num_col);

// variables from structures.c
struct csc {
    int rowind;
	int colind;
	int intval;
	long double floatval;
    // struct csc *next;
};	

extern struct csc *m1csc;

struct csc2 {
    int rowind;
	int colind;
	int intval;
	long double floatval;
    // struct csc *next;
};	
extern struct csc2 *m2csc;

extern int comparator1(const void *p, const void *q);
extern int comparator2(const void *p, const void *q);


// variables from matrixMultiplier.c 
extern void multiplier(FILE *fp);

// variables from freeMemory.c
extern void freeMemory();