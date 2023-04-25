#include <stdio.h>

#define MAXCANDIDATES 100 // maximum number of candidates for a position
#define MAXSOLUTIONS 100  // maximum number of solutions

void backtrack(int a[], int k, int sum, int n, int candidates[], int *ncandidates, int solutions[][MAXCANDIDATES], int *nsolutions);

int main() {
    int n, sum;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int a[n], candidates[n], ncandidates, solutions[MAXSOLUTIONS][MAXCANDIDATES], nsolutions = 0;
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    
    backtrack(a, 0, 0, n, candidates, &ncandidates, solutions, &nsolutions);
    
    printf("All subsets with sum equal to %d:\n", sum);
    for (int i = 0; i < nsolutions; i++) {
        int *subset = solutions[i];
        for (int j = 0; j < ncandidates; j++) {
            printf("%d ", subset[j]);
        }
        printf("\n");
    }
    return 0;
}

void backtrack(int a[], int k, int sum, int n, int candidates[], int *ncandidates, int solutions[][MAXCANDIDATES], int *nsolutions) {
    if (sum == 0) {
        int *subset = solutions[*nsolutions];
        for (int i = 0; i < k; i++) {
            subset[i] = candidates[i];
        }
        (*nsolutions)++;
        return;
    }
    if (sum < 0 || k == n) {
        return;
    }
    candidates[k] = a[k];
    (*ncandidates)++;
    backtrack(a, k + 1, sum - a[k], n, candidates, ncandidates, solutions, nsolutions);
    (*ncandidates)--;
    backtrack(a, k + 1, sum, n, candidates, ncandidates, solutions, nsolutions);
}
