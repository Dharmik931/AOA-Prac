#include <stdio.h>
int min, max;
int a[100];
void minmax(int l, int h)
{
	int mid, max1, min1;
	if (l == h)
	{
    	max = min = a[l];
	}
	else
	{
    	if (l == h - 1)
    	{
        	if (a[l] < a[h])
        	{
            	max = a[h];
            	min = a[l];
        	}
        	else
        	{
            	max = a[l];
            	min = a[h];
        	}
    	}
    	else
    	{
        	mid = (l + h) / 2;
        	minmax(l, mid);
        	minmax(mid + 1, h);
        	max1 = max;
        	min1 = min;
        	if (max < max1)
            	max = max1;
        	if (min > min1)
            	min = min1;
    	}
	}
}
void main()
{
	int n, i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements of the matrix: ");
	for (i = 1; i <= n; i++)
	{
    	scanf("%d", &a[i]);
	}
	max = a[0];
	min = a[0];
	minmax(1, n);
   printf("Minimum element in an array : %d\n", min);
   printf("Maximum element in an array : %d\n", max);
}



//O(n)