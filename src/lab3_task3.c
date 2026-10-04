#include <stdio.h>

/*
 * Name: Dhanusha Veliyannoor Udhayakumar
 * Student ID: 241ADB049
 */

int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}
