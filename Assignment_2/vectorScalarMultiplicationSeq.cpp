#include <omp.h>
#include <pthread.h>
#include <stdio.h>

int main()
{
    int N = 500;
    int mat1[501];
    for (int i = 0; i < N; i++)
        mat1[i] = 10;
    int S = 6;

    double itime;
    itime = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {
        mat1[i] *= S;
        printf("Index: %d Thread: %d\n", i, omp_get_thread_num());
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", mat1[i]);
    }

    double ftime = omp_get_wtime();
    double exec_time = ftime - itime;
    printf("\nTime taken is %f\n", exec_time);
    printf("\n");
}
