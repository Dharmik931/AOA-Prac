#include<stdio.h>
#include<string.h>
void main()
{
    char T[20],P[20];
    printf("Enter target string: ");
    scanf("%s",T);
    printf("Enter pattern string: ");
    scanf("%s",P);
    int n=strlen(T),m=strlen(P);
    for(int i=0;i<n-m;i++)
    {
        int flag=1;
        for(int j=0;j<m;j++)
        {
            if(P[j]!=T[i+j])
                flag=0;
        }
        if(flag)
            printf("Pattern found at position %d",i+1);
    }
}