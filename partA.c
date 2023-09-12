#include <dirent.h>
#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define MAX_LEN 10000

int isDirectory (char* location) {
    DIR* directory = opendir(location); 
    if (directory != NULL ) {
    closedir(directory); 
    return 1; 


} else if ( errno == ENOTDIR) {
    return 0; 
}

return -1; 
}
 


