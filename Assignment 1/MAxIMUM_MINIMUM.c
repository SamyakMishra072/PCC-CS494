#include <stdio.h>

// Function to find the maximum and minimum elements of an array
void findMaxMin(int arr[], int size, int *max, int *min) {
    *max = arr[0]; // Initialize max to the first element
    *min = arr[0]; // Initialize min to the first element

    // Traverse the array to find max and min
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        } else if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int arr[] = {5, 10, 2, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, size, &max, &min);

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}
IMSI: 405672389404767
msisdn: 919775948268
Subscriber-IP-Address: 10.10.142.17
Charging-ID: 1611786533
APN: www
