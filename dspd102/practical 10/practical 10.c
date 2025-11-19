
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file, *dest_file;
    char *source_filename = "input.txt";
    char *dest_filename = "output.txt";
    int c;

    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("Error: Could not open source file %s\n", source_filename);
        exit(1);
    }

    dest_file = fopen(dest_filename, "w");
    if (dest_file == NULL) {
        printf("Error: Could not create destination file %s\n", dest_filename);
        fclose(source_file);
        exit(1);
    }

    while ((c = fgetc(source_file)) != EOF) {
        fputc(c, dest_file);
    }

    printf("Contents successfully copied from %s to %s.\n", source_filename, dest_filename);

    fclose(source_file);
    fclose(dest_file);

    return 0;
}


