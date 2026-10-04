#include <stdio.h>

/*
 * Name: Dhanusha Veliyannoor Udhayakumar
 * Student ID: 241ADB049
 */

void swap(int *x, int *y);
void modify_value(int *x);

void swap(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void modify_value(int *x) {
    *x = *x * 2;
}
