#include <stdio.h>
#include <stdlib.h>

void scan(int arr[], int head, int size)
{
    int distance, total_seek_time = 0;
    int current = head;
    qsort(arr, size, sizeof(int), compare);

    int index = 0;
    while (arr[index] < head)
    {
        index++;
    }

    for (int i = index; i < size; i++)
    {
        distance = abs(arr[i] - current);
        total_seek_time += distance;
        current = arr[i];
        printf("Move from %d to %d with seek %d\n", current - distance, current, distance);
    }

    for (int i = index - 1; i >= 0; i--)
    {
        distance = abs(arr[i] - current);
        total_seek_time += distance;
        current = arr[i];
        printf("Move from %d to %d with seek %d\n", current + distance, current, distance);
    }

    printf("Total Seek Time: %d\n", total_seek_time);
}

void cscan(int arr[], int head, int size)
{
    int distance, total_seek_time = 0;
    int current = head;

    qsort(arr, size, sizeof(int), compare);

    int index = 0;
    while (arr[index] < head)
    {
        index++;
    }

    for (int i = index; i < size; i++)
    {
        distance = abs(arr[i] - current);
        total_seek_time += distance;
        current = arr[i];
        printf("Move from %d to %d with seek %d\n", current - distance, current, distance);
    }

    distance = abs(arr[0] - current) + abs(arr[size - 1] - arr[0]);
    total_seek_time += distance;
    current = arr[0];
    printf("Move from %d to %d with seek %d\n", current + distance, current, distance);

    for (int i = 1; i < index; i++)
    {
        distance = abs(arr[i] - current);
        total_seek_time += distance;
        current = arr[i];
        printf("Move from %d to %d with seek %d\n", current - distance, current, distance);
    }
    printf("Total Seek Time: %d\n", total_seek_time);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int cylinders[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int size = sizeof(cylinders) / sizeof(cylinders[0]);
    printf("Scan Algorithm:\n");
    scan(cylinders, 50, size);
    printf("\nC-Scan Algorithm:\n");
    cscan(cylinders, 50, size);
    return 0;
}