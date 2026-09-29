#include <stdio.h>
#include <stdlib.h>

int main() {

    int *numbers = malloc(5 * sizeof(int));

    if (numbers == NULL) {
        return 1;
    }

    numbers[0] = 10;

    free(numbers);

    printf("Memory released.%d\n", *numbers); // value = 10

    //free(numbers);

    // printf("Memory released.%d\n", *numbers); // value = -2144182720

    return 0;
}