#include <stdio.h>

struct Process {
    int size;
    int originalSerial;
};

// Function to sort an array of Process in descending order based on size
void descendingSort(struct Process arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].size < arr[j + 1].size) {
                // Swap elements if they are in the wrong order
                struct Process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numBlocks, numProcesses;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    struct Process blockProcesses[numBlocks]; // Array of struct Process

    // Input memory block sizes
    printf("\nEnter the size of memory blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockProcesses[i].size);
        blockProcesses[i].originalSerial = i + 1;
    }

    // Sort memory block sizes in descending order
    descendingSort(blockProcesses, numBlocks);

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Process processes[numProcesses];
    int allocation[numProcesses];

    // Input process sizes and original serial numbers
    printf("\nEnter the size of processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].size);
        processes[i].originalSerial = i + 1;
        allocation[i] = -1;
    }

    // Worst-Fit Allocation (Descending Order)
    for (int i = 0; i < numProcesses; i++) {
        int worstFitBlock = -1;
        for (int j = 0; j < numBlocks; j++) {
            if (blockProcesses[j].size >= processes[i].size) {
                if (worstFitBlock == -1 || blockProcesses[j].size > blockProcesses[worstFitBlock].size) {
                    worstFitBlock = j;
                }
            }
        }

        if (worstFitBlock != -1) {
            allocation[i] = worstFitBlock;
            blockProcesses[worstFitBlock].size -= processes[i].size;
        }
    }

    // Display the result
    printf("\nResult:\n\n");
    printf("Process\tMemory Block\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t", processes[i].originalSerial); // Original process serial number
        if (allocation[i] != -1) {
            printf("%d\n", blockProcesses[allocation[i]].originalSerial); // Memory block allocated (1-based)
        } else {
            printf("NA\n");
        }
    }

    // Calculate internal fragmentation
    int internalFragmentation = 0;
    for (int i = 0; i < numBlocks; i++) {
        internalFragmentation += blockProcesses[i].size;
    }

    printf("\nTotal Internal Fragmentation: %d\n", internalFragmentation);

    return 0;
}
