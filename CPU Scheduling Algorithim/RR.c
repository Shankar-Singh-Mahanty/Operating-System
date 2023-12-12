#include <stdio.h>

int main() {
    int n, i, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    int burstTime[n], arrivalTime[n], remainingBurstTime[n], completionTime[n], turnaroundTime[n], waitingTime[n];

    printf("Enter the arrival times and burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0;
    int completed = 0;
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                int executeTime = (remainingBurstTime[i] < timeQuantum) ? remainingBurstTime[i] : timeQuantum;
                currentTime += executeTime;
                remainingBurstTime[i] -= executeTime;

                if (remainingBurstTime[i] == 0) {
                    completed++;
                    turnaroundTime[i] = currentTime - arrivalTime[i];
                    waitingTime[i] = turnaroundTime[i] - burstTime[i];
                    totalTurnaroundTime += turnaroundTime[i];
                    totalWaitingTime += waitingTime[i];
                    completionTime[i] = currentTime;

                    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
                }
            }
        }
    }

    // Calculate and display average TAT and WT
    float avgTurnaroundTime = totalTurnaroundTime / n;
    float avgWaitingTime = totalWaitingTime / n;
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
