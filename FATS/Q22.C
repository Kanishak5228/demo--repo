#include <stdio.h>

void yearToRoman(int year) {
    int decimalValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char roman[1000] = "";
    int i = 0;
    
    while (year > 0) {
        while (year >= decimalValues[i]) {
            year -= decimalValues[i];
            strcat(roman, romanNumerals[i]);
        }
        i++;
    }
    
    printf("%s\n", roman);
}

int main() {
    int year = 1988;
    yearToRoman(year);
    return 0;
}
