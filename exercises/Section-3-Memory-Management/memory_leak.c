#include <stdio.h>
#include <stdlib.h>

int main() {

    int *numbers = malloc(5 * sizeof(int));

    int **p = &numbers;

    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        numbers[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
/*
Memory leaking here. because, free(numbers); is absent. also, setting up number = NULL; setup a good defence,
especially if the pointer might remain in scope and accidentally be reused.
*/
    return 0;
}