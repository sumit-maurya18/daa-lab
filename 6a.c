#include <stdio.h>

// Function to perform Activity Selection
void activitySelection(int start[], int finish[], int n)
{
    printf("Selected activities are:\n");

    // The first activity always gets selected
    int lastSelected = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", lastSelected + 1, start[lastSelected], finish[lastSelected]);

    // Consider the rest of the activities
    for (int i = 1; i < n; i++)
    {
        // If this activity starts after or when the previous one ends
        if (start[i] >= finish[lastSelected])
        {
            printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);
            lastSelected = i;
        }
    }
}

int main()
{
    int startTimes[] = {1, 3, 0, 5, 8, 5};
    int finishTimes[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(startTimes) / sizeof(startTimes[0]);

    printf("Activity Selection Problem (Greedy Approach)\n");
    printf("\n");
    printf("Activities (Start, Finish):\n");
    for (int i = 0; i < n; i++)
        printf("Activity %d: (%d, %d)\n", i + 1, startTimes[i], finishTimes[i]);

    printf("\n");
    activitySelection(startTimes, finishTimes, n);

    return 0;
}
