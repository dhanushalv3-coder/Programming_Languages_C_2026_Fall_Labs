/* Name: Dhanusha Veliyannoor Udhayakumar   Student ID: 241ADB049
 * Week 5 - Task 2: Save and load a struct as text. */
#include <stdio.h>
#include <string.h>

typedef struct Student {
    char  name[50];
    int   age;
    float gpa;
} Student;

/* Writes "name age gpa" on one line. Returns 0 on success, -1 on error. */
int save_student(const Student *s, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }
    int written = fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa);
    int closed  = fclose(fp);
    return (written < 0 || closed != 0) ? -1 : 0;
}

/* Reads one record. Returns 0 on success, -1 on error. */
int load_student(const char *filename, Student *out)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    /* %49s leaves room for the '\0' in name[50]. */
    int n = fscanf(fp, "%49s %d %f", out->name, &out->age, &out->gpa);
    fclose(fp);
    return (n == 3) ? 0 : -1;
}

int main(void)
{
    Student s = {0};
    Student loaded = {0};
    strcpy(s.name, "Alice");
    s.age = 21;
    s.gpa = 3.75f;

    printf("Saving student to file...\n");
    if (save_student(&s, "student.txt") != 0) {
        fprintf(stderr, "Error: could not save student.\n");
        return 1;
    }

    printf("Loading student from file...\n");
    if (load_student("student.txt", &loaded) != 0) {
        fprintf(stderr, "Error: could not load student.\n");
        return 1;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n",
           loaded.name, loaded.age, loaded.gpa);
    return 0;
}
