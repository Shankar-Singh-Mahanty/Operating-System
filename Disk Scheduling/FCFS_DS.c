#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, i;
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
    int totalHeadMovement = 0;
    for (i = 0; i < n; i++) {
        totalHeadMovement += abs(head - requests[i]);
        head = requests[i];
    }
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);
    return 0;
}
