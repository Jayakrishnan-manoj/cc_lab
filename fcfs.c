//Write a program to simulate FCFS scheduling for a set of processes. Input should include arrival time and burst timefor each process, and the program should output the completion time, turnaroundtime, and waiting time for each process.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], completion_time[n], turnaround_time[n], waiting_time[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    //sort the arrival
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }

    completion_time[0] = arrival_time[0] + burst_time[0];
    turnaround_time[0] = completion_time[0] - arrival_time[0];
    waiting_time[0] = turnaround_time[0] - burst_time[0];
    for (i = 1; i < n; i++)
    {
        if (arrival_time[i] > completion_time[i - 1])
        {
            completion_time[i] = arrival_time[i] + burst_time[i];
        }
        else
        {
            completion_time[i] = completion_time[i - 1] + burst_time[i];
        }
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    return 0;
}

