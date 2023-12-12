#include <stdio.h>

int main() {
    int framesize, frame[5];
    int len, refstring[20];
    int pagefault = 0, first = 0;
    int i, j;

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
            frame[first] = refstring[i];

            if (first == framesize - 1)
                first = 0;
            else
                first++;
        }
    }

    printf("Total Page Faults: %d\n", pagefault);
    printf("Total Page Hits: %d\n", len - pagefault);
    printf("Page Fault Percentage: %.2f%%\n", (float)pagefault / len * 100);
    printf("Page Hit Percentage: %.2f%%\n", 100.0 - ((float)pagefault / len * 100));

    return 0;
}
