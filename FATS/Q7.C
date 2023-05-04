#include <stdio.h>
#include <stdlib.h>

int main() {
    char dob[11];
    printf("Enter your date of birth (DD-MM-YYYY): ");
    scanf("%s", dob);

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (dob[i] >= '0' && dob[i] <= '9') {
            sum += dob[i] - '0';
        }
    }

    printf("The sum of all digits in your DOB is: %d\n", sum);

    return 0;
}
