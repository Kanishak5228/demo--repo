#include <stdio.h>

int main() {
    printf("Palindrome numbers between 1 and 500:\n");
    for (int i = 1; i <= 500; i++) {
        int n = i;
        int rev = 0;
        while (n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        if (i == rev) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
