#include <dirent.h>
#include <stdio.h>
#include<stdlib.h>
#include<errno.h>

#include<string.h>
#define MAX_LEN 10000 


int isDirectory (char* location) { //here is the def of the funtion to check
    DIR* directory = opendir(location); //opening using opendir 
    if (directory != NULL ) { //checking if its valid and not null 
    closedir(directory); 
    return 1; 


} else if ( errno == ENOTDIR) { //error handling 
    return 0; 
}

return -1; 
}
 


