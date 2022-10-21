#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2000

void add(int **mat1, int **mat2, int **ans)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void input(int **mat1, int num)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat1[i][j] = num;
        }
    }
}
void displayMatrix(int **mat1)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **mat1 = (int **)malloc(sizeof(int *) * N);
    int **mat2 = (int **)malloc(sizeof(int *) * N);
    int **ans = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        mat1[i] = (int *)malloc(sizeof(int) * N);
        mat2[i] = (int *)malloc(sizeof(int) * N);
        ans[i] = (int *)malloc(sizeof(int) * N);
    }
    input(mat1, 2);
    input(mat2, 2);
    double start = omp_get_wtime();
    add(mat1, mat2, ans);
    double end = omp_get_wtime();
    // display(c);
    printf("Time taken (seq): %f\n", end - start);
}
// vector<vector<int>> mp(n,vector<int>(n,0));
