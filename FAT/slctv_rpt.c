#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int seq;
    bool acked;
} Frame;

int main() {
    int windowSize, frameCount;
    int base = 0;
    int nextSeqNum = 0;
    int i, j;

    srand(time(NULL));

    printf("Window size: ");
    scanf("%d", &windowSize);

    printf("Number of frames: ");
    scanf("%d", &frameCount);

    Frame frames[frameCount];

    for (i = 0; i < frameCount; i++) {
        frames[i].seq = i;
        frames[i].acked = false;
    }

    while (base < frameCount) {
        for (i = base; i < base + windowSize && i < frameCount; i++) {
            if (!frames[i].acked) {
                if (rand() % 10 < 3) {
                    printf("Frame %d lost\n", i);
                    continue;
                }

                printf("Sending frame %d\n", i);

                if (rand() % 10 >= 3) {
                    frames[i].acked = true;
                    printf("Frame %d acknowledgement received\n", i);
                } else {
                    printf("Frame %d acknowledgement not received\n", i);
                }
            }
        }

        while (base < frameCount && frames[base].acked) {
            base++;
        }
    }

    printf("All frames acknowledged. Transmission done.\n");

    return 0;
}