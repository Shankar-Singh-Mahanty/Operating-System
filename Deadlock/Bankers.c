#include <stdio.h>

void main() {
    int i, j, k, ans[10], ind = 0, need[10][10], y, flag, f[10];
    int n, m, alloc[10][10], max[10][10], avail[10];

    // Input: Number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Input: Available resources
    printf("Enter the available resource matrix: ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Input: Allocation matrix
    printf("Enter the allocation matrix:-\n");
    for (i = 0; i < n; i++) {
        printf("Process %d= ", i+1);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Input: Maximum matrix
    printf("Enter the max matrix:-\n");
    for (i = 0; i < n; i++) {
        printf("Process %d= ", i+1);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Initialize flags and need matrix
    for (k = 0; k < n; k++)
        f[k] = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    y = 0;

    // Banker's algorithm for deadlock avoidance
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                flag = 0;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    // Check if the system is in a safe state
    flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The system is not in a safe state.");
            break;
        }
    }

    if (flag == 1) {
        printf("The system is in a safe state. Safe sequence:-\n");
        for (i = 0; i < n; i++)
            printf("%d\t", ans[i]);
    }
}
