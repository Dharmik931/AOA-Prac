#include <stdio.h>
void main()
{
    int n,m;
    printf("Enter number of jobs:");
    scanf("%d", &n);
    int w[n],p[n];
    printf("Enter job weights:");
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter job profits:");
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter knapsack size:");
    scanf("%d",&m);
    float pbw[n];
    for(int i = 0; i < n; i++)
        pbw[i] =p[i]/(float)w[i];
    for(int i = 0; i < n; i++)
        for(int j=0;j<n-i-1;j++)
            if(pbw[j]<pbw[j+1])
            {
                int temp = pbw[j];
                pbw[j]=pbw[j+1];
                pbw[j+1]=temp;

                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
    int Profit=0,rw=m,i=0;
    printf("Jobs in knapsack:\n");
    while(m>0)
    {
        if(m>=w[i])
        {
            m-=w[i];
            printf("1 x %d\n",w[i]);
            Profit+=p[i];
        }
        else
        {
            float x=w[i]/(float)m;
            m-=w[i]/x;
            printf("1/%f x %d\n",x,w[i]);
            Profit+=p[i]/x;
        }
        printf("Remaining space in knapsack:%d\n",m);
        i++;
    }
    printf("Profit:%d\n",Profit);
}





//O(n log n)
