#include <stdio.h>
int main()
{
    int n, pg[30], fr[10];
    int count[10], i, j, k, fault, f, flag, temp, current, c, dist, max, m, cnt, p, x;
    fault = 0;
    dist = 0;
    k = 0;
    printf("Enter the total no pages:\t");
    scanf("%d", &n);
    printf("Enter the sequence:");
    for (i = 0; i < n; i++)
        scanf("%d", &pg[i]);
    printf("\nEnter frame size:");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        count[i] = 0;
        fr[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        flag = 0;
        temp = pg[i];
        for (j = 0; j < f; j++)
        {
            if (temp == fr[j])
            {
                flag = 1;
                break;
            }
        }
        if ((flag == 0) && (k < f))
        {
            fault++;
            fr[k] = temp;
            k++;
        }
        else if ((flag == 0) && (k == f))
        {
            fault++;
            for (cnt = 0; cnt < f; cnt++)
            {
                current = fr[cnt];
                for (c = i; c < n; c++)
                {
                    if (current != pg[c])
                        count[cnt]++;
                    else
                        break;
                }
            }
            max = 0;
            for (m = 0; m < f; m++)
            {
                if (count[m] > max)
                {
                    max = count[m];
                    p = m;
                }
            }
            fr[p] = temp;
        }
        printf("\npage  %d  frame\t", pg[i]);
        for (x = 0; x < f; x++)
        {
            printf("%d\t", fr[x]);
        }
    }
    printf("\nTotal number of faults=%d", fault);
    return 0;
}

// #include <stdio.h>
// int fr[3], n, m;
// void display();
// int main()
// {
//     int i, j, page[20], fs[10];
//     int max, found = 0, lg[3], index, k, l, flag1 = 0, flag2 = 0, pf = 0;
//     float pr;
//     printf("Enter length of the reference string: ");
//     scanf("%d", &n);
//     printf("Enter the reference string: ");
//     for (i = 0; i < n; i++)
//         scanf("%d", &page[i]);
//     printf("Enter no of frames: ");
//     scanf("%d", &m);
//     for (i = 0; i < m; i++)
//         fr[i] = -1;

//     pf = m;
//     for (j = 0; j < n; j++)
//     {
//         flag1 = 0;
//         flag2 = 0;
//         for (i = 0; i < m; i++)
//         {
//             if (fr[i] == page[j])
//             {
//                 flag1 = 1;
//                 flag2 = 1;
//                 break;
//             }
//         }
//         if (flag1 == 0)
//         {
//             for (i = 0; i < m; i++)
//             {
//                 if (fr[i] == -1)
//                 {
//                     fr[i] = page[j];
//                     flag2 = 1;
//                     break;
//                 }
//             }
//         }
//         if (flag2 == 0)
//         {
//             for (i = 0; i < m; i++)
//                 lg[i] = 0;
//             for (i = 0; i < m; i++)
//             {
//                 for (k = j + 1; k <= n; k++)
//                 {
//                     if (fr[i] == page[k])
//                     {
//                         lg[i] = k - j;
//                         break;
//                     }
//                 }
//             }
//             found = 0;
//             for (i = 0; i < m; i++)
//             {
//                 if (lg[i] == 0)
//                 {
//                     index = i;
//                     found = 1;
//                     break;
//                 }
//             }
//             if (found == 0)
//             {
//                 max = lg[0];
//                 index = 0;
//                 for (i = 0; i < m; i++)
//                 {
//                     if (max < lg[i])
//                     {
//                         max = lg[i];
//                         index = i;
//                     }
//                 }
//             }
//             fr[index] = page[j];
//             pf++;
//         }
//         display();
//     }
//     printf("Number of page faults : %d\n", pf);
//     pr = (float)pf / n * 100;
//     printf("Page fault rate = %f \n", pr);
//     return 0;
// }
// void display()
// {
//     int i;
//     for (i = 0; i < m; i++)
//         printf("%d\t", fr[i]);
//     printf("\n");
// }
