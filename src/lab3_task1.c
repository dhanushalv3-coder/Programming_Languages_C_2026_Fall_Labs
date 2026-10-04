#include <stdio.h>

/*
 * Name: Dhanusha Veliyannoor Udhayakumar
 * Student ID: 241ADB049
 */

int array_min(int arr[], int size);
int array_max(int arr[], int size);
int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int array_min(int arr[], int size) {
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int array_max(int arr[], int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int array_sum(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

float array_avg(int arr[], int size) {
    int sum = array_sum(arr, size);

    return (float)sum / size;
}

int main(void) {
    int numbers[] = {12, 5, 9, 2, 15, 8};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Min: %d\n", array_min(numbers, size));
    printf("Max: %d\n", array_max(numbers, size));
    printf("Sum: %d\n", array_sum(numbers, size));
    printf("Average: %.2f\n", array_avg(numbers, size));

    return 0;
}
