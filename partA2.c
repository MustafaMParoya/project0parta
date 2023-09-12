//Part a 
#include <dirent.h>
#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define MAX_LEN 10000


void printDirectories(char* directoryName, int tabCount) { 
    int result = isDirectory(directoryName); 
    if (result != -1 ) {
        if (result ==1) {
            struct dirent **namelist; 
            int n = scandir(directoryName, &namelist, NULL, alphasort); 
            if (n == -1) {
                perror("you can not open this directory! "); 
                exit(1); 
            }
            while (n-- ) {
                for(int i=0; i<tabCount; i+=1 ) {
                    printf("\t"); 
                }
                printf("%s\n", namelist[n]->d_name); 
                char currentFileLocation[ MAX_LEN ] = ""; 
                strcpy(currentFileLocation, directoryName);
                strcat(currentFileLocation, "/");
                strcat(currentFileLocation, namelist[n]->d_name);
                if (strcmp(namelist[n]->d_name, ".") != 0 && strcmp(namelist[n]->d_name, "..") != 0) {
                    if (isDirectory(currentFileLocation) == 1) {
                        printDirectories(currentFileLocation, tabCount+1);

                    }
                }
                free (namelist[n]); 
            }
        } else {
            perror("the given location is not a directory ");
            exit(1);

        }
    } else {
        perror("Directory doesn't exist.");
        exit(1);

    }

}

int main (int argc, char** argv) {
    if (argc> 2) {
        perror("wrong number of arguments "); 
        exit(1); 
    } else {
        if (argc == 1) {
            printDirectories(".", 0);

        } else {
            printDirectories(argv[1], 0);

        }
    }

}