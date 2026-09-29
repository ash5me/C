#include <stdio.h>

int calculate_array_sum(const int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

void walk_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d \n", *arr);
        arr++;
    }
}
// modifies the array
void double_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        (*arr) *= 2;
        printf("%d \n", *arr);
        arr++;
    }
}

// finding max pointer
int find_max_pointer(const int*arr, int size) {
    
    int max = *arr;
    for (int i = 1; i < size; i++) {
    if (*arr > max) {
        max = *arr;
    }
    arr++;
    }
    return max;
}

int main() {
    int numbers[] = {12, 5, 27, 8, 19};
    int *p = numbers;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int max_pointer = find_max_pointer(p,size);
    printf("Max pointer is %d",max_pointer);
}

// int main() {
//     int numbers[] = {1, 2, 3, 4, 5};
//     int *p = numbers;
//     int size = sizeof(numbers) / sizeof(numbers[0]);
//     double_array(p,size);
// }

// int main() {
//     int numbers[] = {10, 20, 30, 40, 50};
//     int *p = numbers;
//     int size = sizeof(numbers) / sizeof(numbers[0]);
//     walk_array(p,size);
// }

// int main() {
//     int numbers[] = {10, 20, 30, 40, 50};
//     int size = sizeof(numbers) / sizeof(numbers[0]);
//     int summation = calculate_array_sum(numbers,size);
//     printf("%d", summation);
// }