/* Name: Dhanusha Veliyannoor Udhayakumar   Student ID: 241ADB049
 * Week 5 - Task 1: Read and write a text file. */
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Optional bonus: file name from the command line. */
    const char *filename = (argc > 1) ? argv[1] : "data.txt";
    char line[256];
    int count = 0;

    printf("Writing lines to %s...\n", filename);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    printf("Reading contents:\n");
    while (fgets(line, sizeof line, fp) != NULL) {
        fputs(line, stdout);   /* line already ends with '\n' */
        count++;
    }
    fclose(fp);

    printf("Lines read: %d\n", count);
    return 0;
}
