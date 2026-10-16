
/*
 * week4_3_struct_database.c
 * Author: Dhanusha Veliyannoor Udhayakumar
 * Student ID: 241ADB049
 * Description:
 *   Creates an in-memory database using an array of structs.
 *   Reads student records, prints them as a table, and frees memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the Student structure.
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Check that the allocation size will not overflow.
    if ((size_t)n > SIZE_MAX / sizeof(struct Student)) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for n Student records.
    students = malloc((size_t)n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read information for each student.
    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);

        if (scanf("%49s %d %f",
                  students[i].name,
                  &students[i].id,
                  &students[i].grade) != 3) {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }
    }

    // Print an empty line before the table.
    printf("\n");

    // Print the table header.
    printf("%-6s %-11s %s\n", "ID", "Name", "Grade");

    // Print each student record in input order.
    for (int i = 0; i < n; i++) {
        printf("%-6d %-11s %.1f\n",
               students[i].id,
               students[i].name,
               students[i].grade);
    }

    // Free the allocated memory.
    free(students);

    return 0;
}

