#include <stdio.h>

// Structure to store item information
struct Item
{
    int weight;
    int value;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items in descending order of value/weight ratio
void sortByRatio(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2)
                swap(&items[j], &items[j + 1]);
        }
    }
}

// Function to perform Fractional Knapsack
double fractionalKnapsack(struct Item items[], int n, int capacity)
{
    sortByRatio(items, n);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= remainingCapacity)
        {
            // Take the full item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        }
        else
        {
            // Take fraction of the item
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main()
{
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    printf("Fractional Knapsack Problem (Greedy Approach)\n");
    printf("\n");

    printf("Items:\n");
    for (int i = 0; i < n; i++)
        printf("Item %d -> Weight: %d, Value: %d, Ratio: %.2f\n",
               i + 1, items[i].weight, items[i].value,
               (double)items[i].value / items[i].weight);

    printf("\nKnapsack Capacity: %d\n\n", capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
