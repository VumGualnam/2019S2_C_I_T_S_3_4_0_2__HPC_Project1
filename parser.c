#include "headers.h"



 		/* two character and \0 */

char operation_requested[Flagsize];
char file1_name[F1size];
char file2_name[F2size];

bool file2_exists = false; 
bool sm = false;
bool tr = false;
bool ad = false;
bool ts = false;
bool mm = false;
bool thread = false;
bool required_logging = false;
float input_scalar;
int input_num_threads;

int parse_command_line(int argc, char** argv)
{
  int c;

  while (1)
    {
      static struct option long_options[] =
        {
			/* These options don’t set a flag.
			We distinguish them by their indices. */
			{"file",    required_argument, 	0, 'f'},
			{"sm",  	required_argument, 	0, 's'},
			{"tr",  	no_argument, 		0, 'r'},
			{"ad",  	no_argument, 		0, 'a'},
			{"ts",  	no_argument, 		0, 'p'},
			{"mm",  	no_argument, 		0, 'm'},
			{"log",    	no_argument, 		0, 'l'},
			{"thread",  required_argument,	0, 't'},
			{0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "f:s:rapmlt:",
                       long_options, &option_index);
					   
      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;
		  
		case 'f':
			strcpy(file1_name, optarg);
			file2_exists = false;
			for ( ; optind < argc && *argv[optind] != '-'; optind++){
				file2_exists = true;
				strcpy(file2_name, argv[optind]);
			}			
			break;
			
        case 's':
		  sm = true;
		  strcpy(operation_requested,"sm");
		  input_scalar = atof(optarg);
          break;

        case 'r':
		   tr = true;
		  strcpy(operation_requested,"tr");
          break;

        case 'a':
		  ad = true;
		  strcpy(operation_requested,"ad");
          break;

        case 'p':
		  ts = true;
		  strcpy(operation_requested,"ts");
          break;
		  
		case 'm':
			mm = true;
		    strcpy(operation_requested,"mm");
			break;

		case 'l':;
			required_logging = true;
			break;
		  
		case 't':
		    thread = true;
			input_num_threads = atoi(optarg);
			break;
			
        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }
	
 return 0;
}