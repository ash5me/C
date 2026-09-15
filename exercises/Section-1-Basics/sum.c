#include <stdio.h>
#ifndef sum_h
#define sum_h
//sum

int calculate_sum(const int arr[], int size) {
    int sum = 0;
    for (int i=0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


int main2() {
    // array
    const int arr[] = {-10, 3, -50, 2};
    const int n = sizeof(arr) / sizeof(arr[0]);
    int summation = calculate_sum(arr,n);
    printf("Here's the sum : %d",summation);
}

#endif