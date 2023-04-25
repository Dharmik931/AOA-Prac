#include<stdio.h>
void main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	int b[n][n];
	printf("Enter the adjacency matrix: \n");
	for(int i=0;i<n;i++)
    	for(int j=0; j<n; j++)
        	scanf("%d",&b[i][j]);
    
	for(int k=0; k<n; k++)
    	for(int i=0; i<n; i++)
        	for(int j=0; j<n; j++)
            	if (b[i][k] + b[k][j] < b[i][j])
                	b[i][j] = b[i][k] + b[k][j];
    

	printf("\nAll pair shortest path is : \n");
	for(int i=0; i<n; i++)
	{
    	for(int j=0; j<n; j++)
        	printf("%d ", b[i][j]);
    	printf("\n");
	}
}






//n^3
