#include <stdio.h>
#include <string.h>

// Function to perform Naive String Matching
void naiveStringMatch(char text[], char pattern[])
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int found = 0;

    printf("Text: %s\n", text);
    printf("Pattern: %s\n\n", pattern);
    printf("Pattern found at positions: ");

    for (int i = 0; i <= textLength - patternLength; i++)
    {
        int j;
        for (j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == patternLength)
        {
            printf("%d ", i);
            found = 1;
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

    printf("Naive String Matching Algorithm\n");
    printf("\n\n");

    naiveStringMatch(text, pattern);

    return 0;
}
