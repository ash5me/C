#include <stdio.h>

int calculate_array_sum(const int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int summation = calculate_array_sum(numbers,size);
    printf("%d", summation);
}