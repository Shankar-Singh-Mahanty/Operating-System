#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, i,j;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                // Swap
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }
    int totalHeadMovement = 0;
    for (i = index; i < n; i++) {
        totalHeadMovement += abs(head - requests[i]);
        head = requests[i];
    }
    totalHeadMovement += (200 - head);
    head = 0;
    for (i = 0; i < index; i++) {
        totalHeadMovement += abs(head - requests[i]);
        head = requests[i];
    }
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);
    return 0;
}





