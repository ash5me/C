#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = malloc(3 * sizeof(int));

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    free(numbers);
/*
  Note : no longer allowed to access the memory of 'numbers'. liftime ended!
*/
    printf("%d\n", numbers[0]); // debugging exercise : Printf statement out of the place. ideally called before freeing memory


    return 0;
}