/* Name: Dhanusha Veliyannoor Udhayakumar   Student ID: 241ADB049
 * Week 5 - Bonus Task 4: Binary file version. */
#include <stdio.h>
#include <string.h>

typedef struct Student {
    char  name[50];
    int   age;
    float gpa;
} Student;

int save_student_binary(const Student *s, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }
    size_t n = fwrite(s, sizeof(Student), 1, fp);
    int closed = fclose(fp);
    return (n == 1 && closed == 0) ? 0 : -1;
}

int load_student_binary(const char *filename, Student *out)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }
    size_t n = fread(out, sizeof(Student), 1, fp);
    fclose(fp);
    return (n == 1) ? 0 : -1;
}

long file_size(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return -1;
    }
    long size = ftell(fp);
    fclose(fp);
    return size;
}

/* Text version from Task 2, needed for the size comparison. */
static int save_student_text(const Student *s, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }
    fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa);
    return (fclose(fp) == 0) ? 0 : -1;
}

int main(void)
{
    Student s = {0};            /* zero-init: no leftover bytes on disk */
    Student loaded = {0};
    strcpy(s.name, "Alice");
    s.age = 21;
    s.gpa = 3.75f;

    printf("Saving student in binary format...\n");
    if (save_student_binary(&s, "student.bin") != 0 ||
        save_student_text(&s, "student.txt") != 0) {
        fprintf(stderr, "Error: could not save files.\n");
        return 1;
    }

    printf("Loading student from binary file...\n");
    if (load_student_binary("student.bin", &loaded) != 0) {
        fprintf(stderr, "Error: could not load binary file.\n");
        return 1;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n",
           loaded.name, loaded.age, loaded.gpa);
    printf("Text file size: %ld bytes\n", file_size("student.txt"));
    printf("Binary file size: %ld bytes\n", file_size("student.bin"));
    return 0;
}
