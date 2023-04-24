#include<stdio.h>
void main()
{
    int n, i, j, temp;
    printf("Enter the number of elememnts to be sorted: ");
    scanf("%d", &n);
    int a[n];
    printf("Eter the elememts of the array: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
        
    
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}