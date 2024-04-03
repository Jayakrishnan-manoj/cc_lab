//shortest time remaining first algorithm in C

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

void sjfp(struct process *p, int n) {
    int time = 0;
    int *remaining_time = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
    }
    while (1) {
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && p[i].arrival_time <= time) {
                flag = 0;
                remaining_time[i]--;
                time++;
                if (remaining_time[i] == 0) {
                    p[i].waiting_time = time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].completion_time = time;
                }
            }
        }
        if (flag) {
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
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival and burst time %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
    }
    sort(p, n);
    sjfp(p, n);
    display(p, n);
    free(p);
    return 0;
}