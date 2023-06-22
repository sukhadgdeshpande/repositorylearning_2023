#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    
    source = fopen("source_file.txt", "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    
    destination = fopen("destination_file.txt", "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(source);
        return 1;
    }

    
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    
    fclose(source);
    fclose(destination);

    return 0;
}