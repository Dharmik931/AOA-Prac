#include <stdio.h>

void binsearch(int a[100], int lower, int upper, int value)
{
    int mid;
    int pos = -1;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (a[mid] == value)
        {
            pos = mid;
            printf("The position is: %d", mid);
            break;
        }
        else if (a[mid] > value)
        {
            upper = mid - 1;
        }
        else{
            lower = mid+1;
        }
    }
}
void main()
{
    int n, i, j, a[100], s;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the element to be searched: ");
    scanf("%d", &s);

    binsearch(a, 0, n - 1, s);
}