#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int i, sum1 = 0, sum2 = 0;

    // Read the value of N from the user
    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Compute the sum of the first series
    for (i = 1; i <= n; i++) {
        sum1 += i * i;
    }

    // Compute the sum of the second series
    int a = 5, r = 5;
    for (i = 1; i <= 10; i++) {
        sum2 += a;
        a *= r;
    }

    // Display the sums of the series
    printf("The sum of the first series is: %d\n", sum1);
    printf("The sum of the second series is: %d\n", sum2);

    return 0;
}
