#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int findLCS(char X[], char Y[], int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("DP Table:\n");
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%2d ", dp[i][j]);
        printf("\n");
    }

    return dp[m][n];
}

int main()
{
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";
    int m = strlen(X);
    int n = strlen(Y);

    printf("Longest Common Subsequence (Dynamic Programming)\n");
    printf("\n");
    printf("String 1: %s\n", X);
    printf("String 2: %s\n\n", Y);

    int lcsLength = findLCS(X, Y, m, n);

    printf("\nLength of Longest Common Subsequence = %d\n", lcsLength);

    return 0;
}
