#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 200
int main()
{
    int *vect;
    int *ans;
    vect = (int *)malloc(sizeof(int) * N);
    ans = (int *)malloc(sizeof(int) * N);
    int b = 10;
    omp_set_num_threads(8);
    for (int i = 0; i < N; i++)
    {
        vect[i] = 0;
    }
    double itime, ftime, exec_time;
    itime = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 8)
    for (int i = 0; i < N; i++)
    {
        ans[i] = vect[i] + b;
    }
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("\n\nTime taken is %f\n", exec_time);
}
