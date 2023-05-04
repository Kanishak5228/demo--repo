#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char* intToRoman(int num);

int main() {
    int num;
    printf("Enter a number to convert to Roman numerals: ");
    scanf("%d", &num);
    char* roman = intToRoman(num);
    printf("%d in Roman numerals is: %s\n", num, roman);
    return 0;
}

char* intToRoman(int num) {
    char* roman = (char*) malloc(sizeof(char) * MAX_SIZE);
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    while(num > 0) {
        if(num >= value[i]) {
            strcat(roman, symbol[i]);
            num -= value[i];
        } else {
            i++;
        }
    }
    return roman;
}
