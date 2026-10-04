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
lab3_t
