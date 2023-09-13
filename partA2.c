//Part a 
#include <dirent.h>
#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define MAX_LEN 10000
//libraries needed 


void printDirectories(char* nameofdirectory , int tabCount) { 
    int result = isDirectory(nameofdirectory ); 
    if (result != -1 ) { //checking if dir exists 
        if (result ==1) {
            struct dirent **namelist; 
            int n = scandir(nameofdirectory , &namelist, NULL, alphasort); 
            if (n == -1) { //scanning directory of contents 
                perror("sorry!! you can not open this directory!! ");  //error messages 
                exit(1); 
            }

            //while loop 
            while (n-- ) {
                for(int i=0; i<tabCount; i+=1 ) {
                    printf("\t"); 
                }
                printf("%s\n", namelist[n]->d_name); 

                //file loc ! finding location in directroy 
                char fileloc[ MAX_LEN ] = ""; 
                strcpy(fileloc, nameofdirectory );
                strcat(fileloc, "/");
                strcat(fileloc , namelist[n]->d_name);


                if (strcmp(namelist[n]->d_name, ".") != 0 && strcmp(namelist[n]->d_name, "..") != 0) {
                    if (isDirectory(fileloc ) == 1) {
                        printDirectories(fileloc , tabCount+1);

                    }
                }

                free (namelist[n]);  //free it up 
            }
        } else {
            perror("tuls can not open. the loc of the directory typed was not correct  ");
            exit(1);

        }
    } else {
        perror("so sorry, but this directory does not exist ! ");
        exit(1);

    }

}

int main (int argc, char** argv) {
    if (argc> 2) { //arguments 
        perror(" this is the incorrect # of arguments given "); 
        exit(1); 
    } else {
        if (argc == 1) {
            printDirectories(".", 0);

        } else {
            printDirectories(argv[1], 0);

        }
    }

}

