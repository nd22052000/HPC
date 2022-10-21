#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int fib(int n)
{
    int i, j;
    if (n < 2)
        return n;
    else
    {
#pragma omp task shared(i)
        {
            printf("%d\n", n);
            printf("%d  first\n", omp_get_thread_num());
            i = fib(n - 1);
        }

#pragma omp task shared(j)
        {
            printf("%d\n", n);
            printf("%d  second\n", omp_get_thread_num());
            j = fib(n - 2);
        }
#pragma omp taskwait
        return i + j;
    }
}

int main()
{
    int n, result;
    printf("Enter number\n");
    scanf("%d", &n);

#pragma omp parallel
    {
#pragma omp single
        result = fib(n);
    }
    printf("Result is %d\n", result);
}
