#include <omp.h>
#include <pthread.h>
#include <stdio.h>

int main()
{
    int N = 1000;
    int mat1[1000];
    for (int i = 0; i < N; i++)
        mat1[i] = 10;

    int mat2[1000];
    for (int i = 0; i < N; i++)
        mat2[i] = 20;

    int ans[1000] = {0};
    double stime = omp_get_wtime();
#pragma omp parallel for reduction(+ \
                                   : ans)
    for (int i = 0; i < N; i++)
    {
        ans[i] = mat1[i] + mat2[i];
        printf("Index: %d Thread: %d\n", i, omp_get_thread_num());
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", ans[i]);
    }

    double etime = omp_get_wtime();
    double time = etime - stime;
    printf("\nTime taken is %f\n", time);
    printf("\n");
    return 0;
}
