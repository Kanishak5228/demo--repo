#include <stdio.h>
#include <string.h>

void bitStuffing(int N, const int arr[]) {
    int brr[30];
    int i = 0, j = 0;

    while (i < N) {
        if (arr[i] == 1) {
            int count = 1;
            brr[j] = arr[i];

            for (int k = i + 1; arr[k] == 1 && k < N && count < 5; k++) {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5) {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        } else {
            brr[j] = arr[i];
        }

        i++;
        j++;
    }

    for (int i = 0; i < j; i++) {
        printf("%d", brr[i]);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    bitStuffing(N, arr);

    return 0;
}