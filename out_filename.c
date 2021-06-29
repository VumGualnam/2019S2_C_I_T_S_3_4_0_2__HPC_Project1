#include "headers.h"  
 
 
char out_filename[OUTPUT_FILENAME_SIZE];

char* out_filename_function(char* operation_req) 
{ 
	
	long int student_id = 22355071;
	
	char underscore[] = "_";
	char file_out_extension[] = ".out";
	
    struct tm *local;
	time_t current_time;
	current_time = time(NULL);
	local = localtime(&current_time);
	int dd = local->tm_mday;
	int mm = local->tm_mon+1;
	int yyyy = local->tm_year+1900;
	int hour = local->tm_hour;
	int minute = local->tm_min;
	
	// char out_filename[29];
	sprintf(out_filename, "%ld%s%02d%02d%d%s%02d%02d%s%s%s", 
						student_id, underscore, dd, mm, yyyy, 
						underscore, hour, minute, 
						underscore, operation_req, file_out_extension);
	return out_filename;
} 