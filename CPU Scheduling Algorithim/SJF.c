#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n], arrivalTime[n], waitingTime[n], completionTime[n], turnaroundTime[n];
    int originalBurstTime[n]; // Store original burst times

    printf("Enter the arrival times and burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        originalBurstTime[i] = burstTime[i]; // Store the original burst time
    }

    int currentTime = 0;
    int completed = 0;
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int shortestJob = -1;
        int shortestBurst = 10000; // Initialize with a large value

        for (i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && burstTime[i] < shortestBurst && burstTime[i] > 0) {
                shortestJob = i;
                shortestBurst = burstTime[i];
            }
        }

        if (shortestJob == -1) {
            currentTime++;
        } else {
            currentTime += burstTime[shortestJob];
            completionTime[shortestJob] = currentTime;
            turnaroundTime[shortestJob] = completionTime[shortestJob] - arrivalTime[shortestJob];
            waitingTime[shortestJob] = turnaroundTime[shortestJob] - originalBurstTime[shortestJob]; // Use original burst time for waiting time
            burstTime[shortestJob] = 0;
            completed++;

            printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", shortestJob + 1, arrivalTime[shortestJob], originalBurstTime[shortestJob], completionTime[shortestJob], turnaroundTime[shortestJob], waitingTime[shortestJob]);

            // Accumulate turnaround and waiting times for calculating averages
            totalTurnaroundTime += turnaroundTime[shortestJob];
            totalWaitingTime += waitingTime[shortestJob];
        }
    }

    // Calculate and display average TAT and WT
    float avgTurnaroundTime = totalTurnaroundTime / n;
    float avgWaitingTime = totalWaitingTime / n;
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
