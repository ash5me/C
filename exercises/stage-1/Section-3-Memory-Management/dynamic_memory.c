#include <stdio.h>
#include <stdlib.h>

void allocate_int(int **ptr) {
    *ptr = malloc(sizeof(int)); // returns address of space for int

}

int main() {
    int *p = NULL;
    allocate_int(&p);
    *p = 42;
    printf("%d\n", *p);
    free(p);
    return 0;
}