//shortest job first algorthm in C. 

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

void sjf(struct process *p, int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        p[i].waiting_time = time - p[i].arrival_time;
        time += p[i].burst_time;
        p[i].turnaround_time = time - p[i].arrival_time;
        p[i].completion_time = time;
    }
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
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
    }
    sort(p, n);
    sjf(p, n);
    display(p, n);
    free(p);
    return 0;
}