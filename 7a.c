#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weight[], int value[], int itemCount)
{
    int dp[itemCount + 1][capacity + 1];

    for (int i = 0; i <= itemCount; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("DP Table:\n");
    for (int i = 0; i <= itemCount; i++)
    {
        for (int w = 0; w <= capacity; w++)
            printf("%3d ", dp[i][w]);
        printf("\n");
    }

    return dp[itemCount][capacity];
}

int main()
{
    int values[] = {10, 20, 30};
    int weights[] = {1, 3, 4};
    int capacity = 6;
    int n = sizeof(values) / sizeof(values[0]);

    printf("0/1 Knapsack Problem (Dynamic Programming)\n");
    printf("\n");

    printf("Items:\n");
    for (int i = 0; i < n; i++)
        printf("Item %d: Weight = %d, Value = %d\n", i + 1, weights[i], values[i]);

    printf("\nKnapsack Capacity: %d\n\n", capacity);

    int maxValue = knapsack(capacity, weights, values, n);

    printf("\nMaximum Value in Knapsack = %d\n", maxValue);

    return 0;
}
