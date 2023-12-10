#include <stdio.h>
// FCFS
int main()
{
    int arrival[5] = {5, 0, 1, 1, 2};
    int burst[5] = {7, 2, 8, 5, 4};
    int wait[5] = {0, 0, 0, 0, 0};
    int tat[5] = {0, 0, 0, 0, 0};
    int sum_wait = 0, sum_tat = 0;
    // selection sort
    for (int i = 0; i < 5 - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arrival[j] < arrival[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            int temp = arrival[i];
            arrival[i] = arrival[min_idx];
            arrival[min_idx] = temp;
            temp = burst[i];
            burst[i] = burst[min_idx];
            burst[min_idx] = temp;
        }
    }
    wait[0] = 0;
    tat[0] = burst[0];
    sum_wait += wait[0];
    sum_tat += tat[0];
    printf("%d %d\n", wait[0], tat[0]);
    for (int i = 1; i < 5; i++)
    {
        wait[i] = wait[i - 1] + burst[i - 1] - arrival[i];
        tat[i] = wait[i] + burst[i];
        printf("%d %d\n", wait[i], tat[i]);
        sum_wait += wait[i];
        sum_tat += tat[i];
    }
printf("Average waiting time: %f\nAverage Turn around time:%f",sum_wait/5.0 , sum_tat/5.0);  
return 0;
}