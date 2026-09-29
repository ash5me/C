#include <stdio.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// swap values using pointers
int main() {
int x = 10;
int y = 20;

printf("Before: x = %d, y = %d\n", x, y);

swap(&x, &y);

printf("After: x = %d, y = %d\n", x, y);
}


