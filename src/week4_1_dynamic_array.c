
/*
 * week4_1_dynamic_array.c
 * Author: Dhanusha Veliyannoor Udhayakumar
 * Student ID: 241ADB049
 * Description:
 *   Creates a dynamic array using malloc, reads integers,
 *   calculates the sum and average, and frees allocated memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;
    long long sum = 0;
    double average;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate memory for n integers.
    arr = malloc((size_t)n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read the integers.
    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }

        sum += arr[i];
    }

    // Calculate the average using floating-point division.
    average = (double)sum / n;

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", average);

    // Release allocated memory.
    free(arr);

    return 0;
}

