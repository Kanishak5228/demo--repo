#include <stdio.h>

int main() {
    int x, y;
    printf("Enter the x coordinate: ");
    scanf("%d", &x);
    printf("Enter the y coordinate: ");
    scanf("%d", &y);

    if (x > 0 && y > 0) {
        printf("The point (%d,%d) is in the first quadrant.\n", x, y);
    }
    else if (x < 0 && y > 0) {
        printf("The point (%d,%d) is in the second quadrant.\n", x, y);
    }
    else if (x < 0 && y < 0) {
        printf("The point (%d,%d) is in the third quadrant.\n", x, y);
    }
    else if (x > 0 && y < 0) {
        printf("The point (%d,%d) is in the fourth quadrant.\n", x, y);
    }
    else {
        printf("The point (%d,%d) is on the origin.\n", x, y);
    }

    return 0;
}
