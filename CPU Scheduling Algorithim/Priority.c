#include <stdio.h>

int main() {
    int n, i;
    int priorityDirection;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the priority direction (1 for higher numbers represent higher priorities, 0 for lower priorities): ");
    scanf("%d", &priorityDirection);

    int burstTime[n], arrivalTime[n], originalBurstTime[n], priority[n], waitingTime[n], completionTime[n], turnaroundTime[n];

    printf("Enter the arrival times, burst times, and priorities for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        originalBurstTime[i] = burstTime[i]; // Store the original burst time
        printf("Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    int currentTime = 0;
    int completed = 0;
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int selectedJob = -1;
        int selectedPriority = priorityDirection ? -1 : 10000; // Initialize with appropriate values

        for (i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && ((priorityDirection && priority[i] > selectedPriority) || (!priorityDirection && priority[i] < selectedPriority)) && burstTime[i] > 0) {
                selectedJob = i;
                selectedPriority = priority[i];
            }
        }

        if (selectedJob == -1) {
            currentTime++;
        } else {
            int remainingBurst = burstTime[selectedJob];
            currentTime += remainingBurst;
            completionTime[selectedJob] = currentTime;
            turnaroundTime[selectedJob] = completionTime[selectedJob] - arrivalTime[selectedJob];
            waitingTime[selectedJob] = turnaroundTime[selectedJob] - originalBurstTime[selectedJob]; // Use original burst time for waiting time
            burstTime[selectedJob] = 0;
            completed++;

            printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", selectedJob + 1, arrivalTime[selectedJob], originalBurstTime[selectedJob], priority[selectedJob], completionTime[selectedJob], turnaroundTime[selectedJob], waitingTime[selectedJob]);

            // Accumulate turnaround and waiting times for calculating averages
            totalTurnaroundTime += turnaroundTime[selectedJob];
            totalWaitingTime += waitingTime[selectedJob];
        }
    }

    // Calculate and display average TAT and WT
    float avgTurnaroundTime = totalTurnaroundTime / n;
    float avgWaitingTime = totalWaitingTime / n;
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
