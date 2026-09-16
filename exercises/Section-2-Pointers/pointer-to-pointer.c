#include <stdio.h>

void set_pointer(int **ptr, int *target) {
    *ptr = target;
}

int main() {
    int a = 10;
    int b = 20;

    int *p = &a;

    printf("%d\n", *p);  // 10

    set_pointer(&p, &b);

    printf("%d\n", *p);  // 20
}