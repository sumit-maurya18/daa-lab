#include <stdio.h>
#include <string.h>
#define d 256 // number of characters in input alphabet

// Function to perform Rabin–Karp String Matching
void rabinKarpSearch(char pattern[], char text[], int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
    int found = 0;

    // The value of h would be "pow(d, m-1) % q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and first window of text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    printf("Text: %s\n", text);
    printf("Pattern: %s\n\n", pattern);
    printf("Pattern found at positions: ");

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
            {
                printf("%d ", i);
                found = 1;
            }
        }

        // Calculate hash value for next window
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }

    if (!found)
        printf("Pattern not found");
    printf("\n");
}

int main()
{
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";
    int q = 101; // prime number for hashing

    printf("Rabin–Karp String Matching Algorithm\n");
    printf("\n\n");

    rabinKarpSearch(pattern, text, q);

    return 0;
}
