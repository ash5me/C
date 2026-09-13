#include <stdio.h>

// Find min
int find_min(const int arr[], int size) {
    // arr[0] is the min
    int min = arr[0];
    // for loop i=1; i<size; i++ (if loop arr[i] < min) then min = arr[i]
    int i = 0;
    for (i=1; i<size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


// Find max
int find_max(const int arr[], int size) {
    int max = arr[0];
    // for - iterating array | compare (if) with other elements i,e starts with 1 then iterate rest of the loop | IF -> first element > max | then that is the max
    //int i = 0;
    for (int i=1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
// Find sum
// Find avg
int main() {
    const int arr [] = {-10, -3, -50, -2};
    const int n = sizeof(arr) / sizeof(arr[0]);
    int max_val = find_max(arr,n);
    printf("Maximum value : %d", max_val);
}