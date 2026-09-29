#include <stdio.h>

void reverse_array(int *arr, int size) {
    int *left = arr;
    int *right = arr + size - 1;

    while (left < right) {
        // swap the values
        int temp = *left;
        *left = *right;
        *right = temp;
        // walking the array towards the middle
        left++;
        right--;
    }
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    reverse_array(numbers, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
}