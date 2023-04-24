#include <stdio.h>



int qsort(int a[20], int lb, int ub)
{
    if (lb < ub)
    {
        int pivot = a[lb];
        int start = lb;
        int end = ub;
        while (start < end)
        {
            while (a[start] <= pivot)
            {
                start++;
            }
            while (a[end] > pivot)
            {
                end--;
            }

            if (start < end)
            {
                int temp;
                temp = a[start];
                a[start] = a[end];
                a[end] = temp;
            }
        }
        int temp;
        temp = a[pivot];
        a[pivot] = a[end];
        a[end] = temp;

        qsort(a, lb, end - 1);
        qsort(a, end + 1, ub);
    }
}

// void qsort(int a[], int lb, int ub)
// {
//     if(lb<ub)
//     {
//         int loc = partition(a, lb, ub);
//         qsort(a, lb, loc-1);
//         qsort(a, loc+1, ub);
//     }
// }

void main()
{
    int i, j, n, a[10], min, temp;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter array of elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    qsort(a, 0, n - 1);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}