//round robin algorithm in C

#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void sort(struct process *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void rr(struct process *p, int n, int quantum) {
    int time = 0;
    int *remaining_time = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
    }
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    p[i].waiting_time = time - p[i].arrival_time - p[i].burst_time;
                    remaining_time[i] = 0;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].completion_time = time;
                }
            }
        }
        if (done) {
            break;
        }
    }
    free(remaining_time);
}

void display(struct process *p, int n) {
    printf("PID\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
    }
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
    }
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    sort(p, n);
    rr(p, n, quantum);
    display(p, n);
    free(p);
    return 0;
}