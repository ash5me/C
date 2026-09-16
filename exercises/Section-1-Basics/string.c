#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int my_strlen(const char *str) {
    int count =0;

        while (*str != '\0') {
            count += 1;
            str++;
        }

    return count;
}

void my_strcpy(char *destination, const char *source) {
     while (*source != '\0'){
        *destination = *source; // copy source value
        destination++;
        source++;
    }
    *destination = *source;
}

bool my_strcmp(char *str1, char *str2) {

    while (*str1 != '\0' && *str2 != '\0') {
        // Either the strings differ, or both reach '\0'.
        if (*str1 != *str2) {
        return false;
        }
        str1++;
        str2++;
    }

    return *str1 == '\0' && *str2 == '0';
    
}

int main() {
    char firstName[] = ("Ashok");
    char secondName[] = ("Ashxo");
    bool compare = my_strcmp(firstName,secondName);
    printf("Compared result : %d\n", compare);
    return 0;
}

// int main() {
//     char source[] = "Hello";
//     char destination[20];
//     my_strcpy(destination, source);
//     printf("%s\n", destination);
//     strcpy(destination, source);
//     printf("%s", destination);
// }

// int main() {
//     char text[] = "Hello";
//     int length = my_strlen(text);
//     printf("Size is : %d", length);
//     printf("Size is : %d\n", sizeof(text));
//     printf("Size is : %zu", strlen(text));
// }