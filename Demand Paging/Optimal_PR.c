#include <stdio.h>

int main() {
    int framesize, frame[7];
    int len, refstring[30];
    int pagefault = 0, i, j;

    printf("Enter the number of page references: ");
    scanf("%d", &len);

    printf("Enter the page references:\n");
    for (i = 0; i < len; i++) {
        printf("PF %d: ", i + 1);
        scanf("%d", &refstring[i]);
    }

    printf("Enter the frame size: ");
    scanf("%d", &framesize);

    for (i = 0; i < framesize; i++)
        frame[i] = -1;

    for (i = 0; i < len; i++) {
        int avail = 0;

        for (j = 0; j < framesize; j++)
            if (frame[j] == refstring[i]) {
                avail = 1;
                break;
            }

        if (avail == 0) {
            pagefault++;

            int maxDist = -1, replaceIndex = -1;
            for (j = 0; j < framesize; j++) {
                int dist = 0, k;
                for (k = i + 1; k < len; k++) {
                    dist++;
                    if (frame[j] == refstring[k])
                        break;
                }
                if (k == len) {
                    replaceIndex = j;
                    break;
                }
                if (dist > maxDist) {
                    maxDist = dist;
                    replaceIndex = j;
                }
            }

            frame[replaceIndex] = refstring[i];
        }
    }

    printf("Total Page Faults: %d\n", pagefault);
    printf("Total Page Hits: %d\n", len - pagefault);
    printf("Page Fault Percentage: %.2f%%\n", (float)pagefault / len * 100);
    printf("Page Hit Percentage: %.2f%%\n", 100.0 - ((float)pagefault / len * 100));

    return 0;
}