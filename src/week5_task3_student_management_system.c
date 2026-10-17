/* Name: Dhanusha Veliyannoor Udhayakumar   Student ID: 241ADB049
 * Week 5 - Task 3: Student management system with file persistence. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN     50
#define DATA_FILE    "students.txt"

typedef struct Student {
    char  name[NAME_LEN];
    int   id;
    float gpa;
} Student;

/* Safe line reader: strips the newline, returns 0 on EOF/error. */
static int read_line(char *buf, size_t size)
{
    if (fgets(buf, (int)size, stdin) == NULL) {
        return 0;
    }
    buf[strcspn(buf, "\r\n")] = '\0';
    return 1;
}

/* Loads records from students.txt. Missing/empty file -> 0 records. */
int load_students(Student arr[], int max)
{
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        return 0;                       /* first run: not an error */
    }
    char line[256];
    int count = 0;
    while (count < max && fgets(line, sizeof line, fp) != NULL) {
        Student s;
        if (sscanf(line, "%49[^,],%d,%f", s.name, &s.id, &s.gpa) == 3) {
            arr[count++] = s;           /* blank/malformed lines are skipped */
        }
    }
    fclose(fp);
    return count;
}

/* Overwrites students.txt with all records. 0 on success, -1 on error. */
int save_students(const Student arr[], int count)
{
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        return -1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    return (fclose(fp) == 0) ? 0 : -1;
}

/* Prompts for a student, validates input, appends to the array. */
void add_student(Student arr[], int *count)
{
    char name[128], id_buf[64], gpa_buf[64];
    char *end;

    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students (limit reached)\n");
        return;
    }

    printf("Enter name: ");
    if (!read_line(name, sizeof name)) { name[0] = '\0'; }
    printf("Enter ID: ");
    if (!read_line(id_buf, sizeof id_buf)) { id_buf[0] = '\0'; }
    printf("Enter GPA: ");
    if (!read_line(gpa_buf, sizeof gpa_buf)) { gpa_buf[0] = '\0'; }

    long id = strtol(id_buf, &end, 10);
    int id_ok = (id_buf[0] != '\0' && *end == '\0' && id >= 0 && id <= 2147483647L);

    double gpa = strtod(gpa_buf, &end);
    int gpa_ok = (gpa_buf[0] != '\0' && *end == '\0' && gpa >= 0.0 && gpa <= 4.0);

    int name_ok = (name[0] != '\0' && strchr(name, ',') == NULL
                   && strlen(name) < NAME_LEN);

    if (!name_ok || !id_ok || !gpa_ok) {
        printf("Invalid input. Student not added.\n");
        return;
    }

    strcpy(arr[*count].name, name);
    arr[*count].id  = (int)id;
    arr[*count].gpa = (float)gpa;
    (*count)++;
    printf("Student added successfully!\n");
}

/* Prints a table of all students. */
void list_students(const Student arr[], int count)
{
    if (count == 0) {
        printf("No students found\n");
        return;
    }
    printf("%-5s %-20s %s\n", "ID", "Name", "GPA");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
}

int main(void)
{
    Student students[MAX_STUDENTS];
    int count = load_students(students, MAX_STUDENTS);
    char buf[64];

    printf("Loaded %d student(s) from %s\n", count, DATA_FILE);

    for (;;) {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n2. Add student\n3. Save and Exit\n");
        printf("Select an option: ");

        /* End of input behaves like option 3. */
        if (!read_line(buf, sizeof buf) || buf[0] == '3') {
            break;
        }
        if (buf[0] == '1')      { list_students(students, count); }
        else if (buf[0] == '2') { add_student(students, &count); }
        else                    { printf("Invalid option.\n"); }
    }

    if (save_students(students, count) != 0) {
        fprintf(stderr, "Error: could not save data.\n");
        return 1;
    }
    printf("Data saved. Goodbye!\n");
    return 0;
}
