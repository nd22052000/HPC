// #include <stdio.h>
// #include <stdlib.h>
// #include <omp.h>
// #define N 200
// int main()
// {
//     int *a;
//     int *c;
//     a = (int *)malloc(sizeof(int) * N);
//     c = (int *)malloc(sizeof(int) * N);
//     int b = 10;
//     omp_set_num_threads(6);
//     for (int i = 0; i < N; i++)
//     {
//         a[i] = 0;
//     }
//     double itime, ftime, exec_time;
//     itime = omp_get_wtime();
// #pragma omp parallel for schedule(static, )
//     for (int i = 0; i < N; i++)
//     {
//         c[i] = a[i] + b;
//     }
//     ftime = omp_get_wtime();
//     exec_time = ftime - itime;
//     printf("\n\nTime taken is %f\n", exec_time);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 10
void hello_world()
{
    printf("Hello world\n");
}
void bye(int i)
{
    printf("Bye: %d\n", i);
}
int main()
{
    int *a = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        a[i] = 1;
    }
#pragma omp parallel
    {
#pragma omp for nowait
        for (int i = 0; i < N; i++)
        {
            bye(i);
        }
        hello_world();
    }
}
