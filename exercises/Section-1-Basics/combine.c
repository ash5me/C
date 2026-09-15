#include <stdio.h>
#include "sum.c"
#include "min_n_max.c"
#include "avg.c"

void combineEverything(int arr[],int size) {
    printf("Please enter %d numbers : \n", size);
    for (int i=0; i < size; i++) {
        printf(" Enter number %d : \n",i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int size = 10;
    int my_arr[10];
    combineEverything(my_arr,size);
    printf("\nYou Entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", my_arr[i]);
    }
    printf("\n");

    // min
    int minimum = find_min(my_arr,size);
    printf("Minimum value : %d\n", minimum);

    // max
    int maximum = find_max(my_arr,size);
    printf("Maximum value : %d\n", maximum);

    //sum
    int sum = calculate_sum(my_arr,size);
    printf("Sum : %d\n", sum);

    //avg
    double avg = calculate_avg(my_arr,size);
    printf("Average value : %.2f\n", avg);
}