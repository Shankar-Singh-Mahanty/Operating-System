#include <stdio.h>
#include <stdlib.h>

// Initializing the mutex variable with the value 1.
int mutex = 1;      // mutal exclusion
// Initializing the full variable with the value 0.
int full = 0;
// empty variable will store the number of empty slots in the buffer.
int empty = 5, data = 0;

// A function that will resemble producers' production of data
int main() {
    int n, i;
    printf("\n1. Enter 1 for Producer"
           "\n2. Enter 2 for Consumer"
           "\n3. Enter 3 to Exit");

    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        // using switch case as there can be multiple types of choice.
        switch (n) {
        case 1:
            // If the value of mutex is 1 and the buffer is not full, then we can produce the data
            if ((mutex == 1) && (empty != 0)) {
                --mutex;
    // Increase the number of full slots
                ++full;
    // decrementing the number of slots available
                --empty;
    // incrementing data which means that the data is produced.
                data++;
                printf("\nProducer produces item number: %d\n", data);
    // incrementing the value of mutex
                ++mutex;
            }
            // else, the buffer must be full.
            else {
                printf("\nThe Buffer is full. New data cannot be produced!");
            }
            break;

        case 2:
            // If the value of mutex is 1 and the buffer is not empty, then we can consume the data
            if ((mutex == 1) && (full != 0)) {
                // decrementing the value of mutex
                --mutex;
    // Decrease the number of full slots
                --full;
    // incrementing the number of slots available
                ++empty;
                printf("\nConsumer consumes item number: %d.\n", data);
    // since data is consumed, let us decrease the value of data
                data--;
    // incrementing the value of mutex
                ++mutex;
            }
            // else, the buffer must be empty.
            else {
                printf("\nThe Buffer is empty! New data cannot be consumed!");
            }
            break;
        // Exit Condition
        case 3:
            printf("\nExited Successfully");
            exit(0);
            break;
        }
    }
}