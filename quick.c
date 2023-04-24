#include<stdio.h>
void Quick_sort(int a[20],int First,int Last)
{
    int i,j,pivot,temp=0;
    if(First<Last)
    {
     pivot=First;
     i=First;
     j=Last;
     while(i<j){
     while(a[i]<=a[pivot] && i<Last)
     i++;
     while(a[j]>a[pivot])
     j--;
     if(i<j)
     {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
     }
     }
    
    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    Quick_sort(a,First,j-1);
    Quick_sort(a,j+1,Last);
    }
}
void main()
{
    int i,n,a[20];
    printf("Enter the element:");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Quick_sort(a,0,n-1);
     printf("Result\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);

}