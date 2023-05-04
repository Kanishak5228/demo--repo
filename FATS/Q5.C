#include <stdio.h>

int string_to_int(char *str) {
    int result = 0;
    while (*str) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int num = string_to_int(str);
    printf("The integer value is: %d\n", num);
    return 0;
}
