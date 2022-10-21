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
    int *vect = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        vect[i] = 1;
    }
#pragma omp parallel for

    // #pragma omp for nowait
    for (int i = 0; i < N; i++)
    {
        bye(i);
    }
    hello_world();
}