#include <stdio.h>
#ifndef avg_h
#define avg_h

/* avg = sum / total no of elements */

double calculate_avg(const int arr[],int size) {
    int sum = 0;
    for (int i=0; i < size; i++) {
        sum += arr[i];
    }
    double avg = (double) sum / size;
    return avg;
}


int main3() {
    // avg
    const int arr[] = {5, 2, 9, 1, 7};
    const int size = sizeof(arr) / sizeof(arr[0]);
    double avg_value = calculate_avg(arr,size);
    printf("Avg value is %.2f", avg_value);
}

#endif