#include<stdio.h>
void main()
{
    int n, i, j;
    printf("Enter the number of elememnts to be sorted: ");
    scanf("%d", &n);
    int a[n];
    printf("Eter the elememts of the array: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    int small;
    j=i+1;
    for(i=0;i<n-1;i++)
    {
        small=i;
        for(j=i+1;j<n;j++)
        {
            int temp;

            if(a[j]<a[small])
            {
                small=j;
                
                temp=a[small];
                a[small]=a[i];
                a[i]=temp;
            }
        }
    }
        
    
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}