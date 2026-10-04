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

int main() {
    int a = 5, b = 10;
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
    
    printf("\nBefore modify: a = %d\n", a);
    modify_value(&a);
    printf("After modify: a = %d\n", a);
    
    return 0;
}
