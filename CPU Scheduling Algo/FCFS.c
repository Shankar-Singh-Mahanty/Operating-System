#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n], arrivalTime[n], waitingTime[n], completionTime[n], turnaroundTime[n];

    printf("Enter the arrival times and burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Calculate completion times, turnaround times, and waiting times based on arrival times
    completionTime[0] = arrivalTime[0] + burstTime[0];
    turnaroundTime[0] = completionTime[0] - arrivalTime[0];
    waitingTime[0] = turnaroundTime[0] - burstTime[0];

    for (i = 1; i < n; i++) {
        // Calculate turnaround time for the current process
        turnaroundTime[i] = completionTime[i - 1] - arrivalTime[i] + burstTime[i];

        // Calculate waiting time for the current process
        if (arrivalTime[i] > completionTime[i - 1]) {
            waitingTime[i] = 0; // No waiting time if the process arrives after the previous one is completed.
        } else {
            waitingTime[i] = turnaroundTime[i] - burstTime[i];
        }

        // Calculate completion time for the current process
        completionTime[i] = arrivalTime[i] + burstTime[i] + waitingTime[i];
    }

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
