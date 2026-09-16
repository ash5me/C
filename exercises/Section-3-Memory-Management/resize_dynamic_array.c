#include <stdio.h>
#include <stdlib.h>

int *create_array(int size) {
    int *arr = malloc(size * sizeof(int));
    return arr;
}

int *resize_array(int *arr, int old_size, int new_size) {
    int *temp = realloc(arr, new_size*sizeof(*arr));
    if (temp == NULL) {
        // allocation failed
        return arr;
    }
    return temp;
}

int *create_zeroed_array(int size) {
    int *arr = calloc(size,sizeof(int));
    return arr;
}

int main() {
    int *numbers = create_zeroed_array(5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    free(numbers);
}

// int main() {
//     int *numbers = create_array(3);
//     numbers[0] = 10;
//     numbers[1] = 20;
//     numbers[2] = 30;
//     numbers = resize_array(numbers, 3, 5);
//     numbers[3] = 40;
//     numbers[4] = 50;
//     for (int i = 0; i < 5; i++) {
//     printf("%d ", numbers[i]);
//     }
//     free(numbers);
//     return 0;
// }