#include <stdio.h>
#include <stdlib.h>

int *create_array(int size) {
    int *arr = malloc(size * sizeof(int));
    return arr;
}

int main() {
    int *numbers = create_array(5);

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    printf("%d\n", numbers[3]);

    free(numbers);

    return 0;
}