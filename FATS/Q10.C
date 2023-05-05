#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to swap two strings using pointers
void swapStrings(char *str1, char *str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Function to concatenate two strings without using strcat
void concatenateStrings(char *str1, char *str2, char *result) {
    int i, j;

    // Copy the characters of the first string to the result string
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    // Append the characters of the second string to the result string
    for (j = 0; str2[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }

    // Add the null character at the end of the result string
    result[i + j] = '\0';
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    char result[MAX_LENGTH * 2];

    // Read the two strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Swap the two strings using pointers
    char *ptr1 = str1;
    char *ptr2 = str2;
    swapStrings(&ptr1, &ptr2);
    printf("After swapping, the strings are: %s %s\n", ptr1, ptr2);

    // Concatenate the two strings using pointers
    concatenateStrings(str1, str2, result);
    printf("The concatenated string is: %s\n", result);

    return 0;
}
