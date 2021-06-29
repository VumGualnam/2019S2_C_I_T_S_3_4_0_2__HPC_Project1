#include "headers.h"

struct csc *m1csc;
struct csc2 *m2csc;



int comparator1(const void *p, const void *q)  
{ 
    int l = ((struct csc *)p)->colind; 
    int r = ((struct csc *)q)->colind;  
    return (l - r); 
}

int comparator2(const void *p, const void *q)  
{ 
    int l = ((struct csc2 *)p)->colind; 
    int r = ((struct csc2 *)q)->colind;  
    return (l - r); 
}