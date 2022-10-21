// C Program to find the minimum scalar product of two vectors
// (dot product)
#include <stdio.h>
#include <time.h>
#define n 100000
int sort(int arr[])
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    return 0;
}

int sortDesc(int arr[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    return 0;
}
int main()
{
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = 10;
    }
    for (int i = 0; i < n; i++)
    {
        arr2[i] = 20;
    }
    clock_t t = clock();
    sort(arr1);
    sortDesc(arr2);
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken (seq): %f\n", time);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("%d\n", sum);
    return 0;
}