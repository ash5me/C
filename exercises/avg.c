#include <stdio.h>

/* avg = sum / total no of elements */

double calculate_avg(const int arr[],int size) {
    int sum = 0;
    for (int i=0; i < size; i++) {
        sum += arr[i];
        int avg = sum / i;
    }
}

int main() {
    const int arr[] = {5, 2, 9, 1, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);
    int avg_value = calculate_avg(arr,size);
    printf("Avg value is %d", avg_value);
}