#include <stdio.h>

int main() {
    int framesize, len, i, j, k;
    int refstring[30], frame[7];
    int pagefault = 0, least, access[20];

    printf("Enter the number of page references: ");
    scanf("%d", &len);

    printf("Enter the page references:\n");
    for (i = 0; i < len; i++) {
        printf("PF %d: ", i + 1);
        scanf("%d", &refstring[i]);
    }

    printf("Enter the frame size: ");
    scanf("%d", &framesize);

    for (i = 0; i < framesize; i++) {
        frame[i] = -1;
        access[i] = 0;
    }
    for (i = 0; i < len; i++) {
        int avail = 0;
        for (j = 0; j < framesize; j++)
            if (frame[j] == refstring[i]) {
                avail = 1;
                access[j]++;
                break;
            }
        if (avail == 0) {
            int dm = 0;
            pagefault++;
            for (k = 0; k < framesize; k++)
                if (frame[k] == -1) {
                    dm = 1;
                    break;
                }
            if (dm == 1) {
                frame[k] = refstring[i];
                access[k]++;
            } else {
                least = 0;
                for (k = 1; k < framesize; k++)
                    if (access[k] < access[least])
                        least = k;
                frame[least] = refstring[i];
                access[least]++;
            }
        }
    }

    float pageFaultPercentage = (float)pagefault / len * 100;
    float pageHitPercentage = ((float)(len - pagefault) / len) * 100;

    printf("\nTotal Page Faults: %d\n", pagefault);
    printf("Total Page Hits: %d\n", len - pagefault);
    printf("Page Fault Percentage: %.2f%%\n", pageFaultPercentage);
    printf("Page Hit Percentage: %.2f%%\n", pageHitPercentage);

    return 0;
}
