#include <stdio.h>
#include <string.h>

void kmp_search(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    int j = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    int i = 1;
    lps[0] = 0;  // lps[0] is always 0
    while (i < M) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    // Search for pattern in txt using lps[]
    i = 0;  // index for txt[]
    j = 0;  // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("Pattern found at index %d\n", i-j);
            j = lps[j-1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
}
 
int main() {
    char txt[100], pat[100];
    printf("Enter the text: ");
    gets(txt);
    printf("Enter the pattern: ");
    gets(pat);
    kmp_search(pat, txt);
    return 0;
}


//n
