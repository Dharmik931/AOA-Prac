#include <stdio.h>
#include <stdbool.h>
#define N 4
int i, j, n;

bool isSafe(int b[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i <= col - 1; i++)
        if (b[row][i] == 1)
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (b[i][j] == 1)
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (b[i][j] == 1)
            return false;
    return true;
}

bool solve(int b[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(b, i, col))
        {
            b[i][col] = 1;
            if (solve(b, col + 1))
                return true;
            b[i][col] = 0;
        }
    }
    return false;
}

void main()
{
    int b[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b[i][j] = 0;
    if (solve(b, 0) == false)
        printf("No Solution\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
}
