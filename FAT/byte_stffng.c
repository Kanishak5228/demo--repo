#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 50
#define FLAG "f"
#define ESCAPE "e"

int main()
{
    char ar[MAX_STR_LEN * 2][MAX_STR_LEN];
    char str[MAX_STR_LEN][MAX_STR_LEN];
    int k = 0, n;

    strcpy(ar[k++], FLAG);

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (int i = 0; i <= n; i++) {
        fgets(str[i], MAX_STR_LEN, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }

    for (int i = 1; i <= n; i++) {
        if (strcmp(str[i], FLAG) != 0 && strcmp(str[i], ESCAPE) != 0) {
            strcpy(ar[k++], str[i]);
        } else {
            strcpy(ar[k++], ESCAPE);
            strcpy(ar[k++], str[i]);
        }
    }

    strcpy(ar[k++], FLAG);

    printf("\nByte stuffing:\n");
    for (int i = 0; i < k; i++) {
        printf("%s\t", ar[i]);
    }
    printf("\n");

    return 0;
}