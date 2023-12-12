#include <stdio.h>

int main() {
    int numBlocks, numProcesses;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    int blockSize[numBlocks];

    // Input memory block sizes
    printf("\nEnter the size of memory blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);

    int processSize[numProcesses];
    int allocation[numProcesses];

    // Input process sizes
    printf("\nEnter the size of processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    // First-Fit Allocation
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Display the result
    printf("\nResult:\n\n");
    printf("Process\tMemory Block\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t", i + 1); // Process number (1-based)
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1); // Memory block allocated (1-based)
        } else {
            printf("NA\n");
        }
    }

    // Calculate internal fragmentation
    int internalFragmentation = 0;
    for (int i = 0; i < numBlocks; i++) {
        internalFragmentation += blockSize[i];
    }

    printf("\nTotal Internal Fragmentation: %d\n", internalFragmentation);

    return 0;
}
