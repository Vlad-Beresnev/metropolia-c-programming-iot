#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINESIZE 80
#define LINECOUNT 100

int to_upper_letters(char *filename) {
    int lc = 0;
    FILE *file;
    char line[LINESIZE];
    char arr[100][80];
    filename[strcspn(filename, "\n")] = '\0';
    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: %s wasn't openned!\n", filename);
        exit(1);
    } else {
        while(lc < 100 && !feof(file)) {
            if(fgets(arr[lc], LINESIZE, file) != NULL) {
                lc++;
            }
        }
    }

    fclose(file);
    
    for (int i = 0; i < lc; i++) {
        for (int j = 0; arr[i][j] != '\n'; j++) 
        arr[i][j] = toupper((unsigned char)arr[i][j]);
    }

    file = fopen(filename, "w");

    for (int k = 0; k < lc; k++) {
        fputs(arr[k], file);
    }

    fclose(file);
    return 0;
}

int main(void) {
    char filename[32];
    printf("Enter file name: ");
    fgets(filename, 32, stdin);
    to_upper_letters(filename);
}