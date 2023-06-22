#include <stdio.h>
#include <ctype.h>
#include <string.h>

void copyFile(FILE *source, FILE *destination, int option) {
    char line[1000];

    while (fgets(line, sizeof(line), source)) {
        int length = strlen(line);
        int i;

        if (option == 1) {
            for (i = 0; i < length; i++) {
                line[i] = toupper(line[i]); 
            }
        } else if (option == 2) {
            for (i = 0; i < length; i++) {
                line[i] = tolower(line[i]); 
            }
        } else if (option == 3) {
            int sentence_start = 1;

            for (i = 0; i < length; i++) {
                if (sentence_start && isalpha(line[i])) {
                    line[i] = toupper(line[i]); 
                    sentence_start = 0;
                } else if (!isalpha(line[i])) {
                    sentence_start = 1;
                } else {
                    line[i] = tolower(line[i]);
                }
            }
        }

        fputs(line, destination);
    }
}

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    int option = 0;

    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <source_file> <destination_file> [-u | -l | -s]\n");
        return 1;
    }

   
    source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    
    destination = fopen(argv[2], "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(source);
        return 1;
    }

    if (argc >= 4) {
        if (strcmp(argv[3], "-u") == 0) {
            option = 1;
        } else if (strcmp(argv[3], "-l") == 0) {
            option = 2;
        } else if (strcmp(argv[3], "-s") == 0) {
            option = 3;
        } else {
            printf("Invalid option.\n");
            fclose(source);
            fclose(destination);
            return 1;
        }
    }

   
    copyFile(source, destination, option);

    printf("File copied successfully.\n");

    
    fclose(source);
    fclose(destination);

    return 0;
}