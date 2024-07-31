#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0]; // Assume the first element is the maximum
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if a larger element is found
        }
    }
    
    return max;
}

int main() {
    int arr[] = {5, 10, 2, 8, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int max = findMax(arr, size);
    
    printf("The largest element in the array is: %d\n", max);
    
    return 0;
}

