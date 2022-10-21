#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;
// Hello World Program

// int main(int argc, char *argv[])
// {

// #pragma omp parallel
// 	{
// 		printf("thread No. %d  Hello World\n", omp_get_thread_num());
// 	}
// 	return 0;
// }

static int sum = 0;

// This is for parallel processing ...Calculates time for parallel processes

int main(int argc, char *argv[])
{

	double itime, ftime, exec_time;
	itime = omp_get_wtime();
#pragma omp parallel for reduction(+ \
								   : sum)

	for (int i = 1; i <= 100; i++)
	{
		// if (i % 8 == omp_get_thread_num())
		// {
		printf("Thread No %d Number :%d Square  :%d \n", omp_get_thread_num(), i, i * i);
		sum += i * i;
		// }
	}
	printf("Sum is %d  ", sum);
	cout << endl;
	ftime = omp_get_wtime();
	exec_time = (ftime - itime);
	printf("\n\nTime taken is %f", exec_time);

	return 0;
}

// This is for serial processing .Calculates time for serial processing..

// int main()
// {
// 	double itime, ftime, exec_time;
// 	itime = omp_get_wtime();
// 	// #pragma omp parallel

// 	for (int i = 1; i <= 100; i++)
// 	{
// 		// if (i % 8 == omp_get_thread_num())
// 		// {
// 		// 	printf("Thread No %d Number :%d Square  :%d \n", omp_get_thread_num(), i, i * i);
// 		printf("Square is %d \n", i * i);
// 		sum += i * i;
// 		// }
// 	}
// 	printf("Sum is %d  ", sum);
// 	cout << endl;
// 	ftime = omp_get_wtime();
// 	exec_time = (ftime - itime);
// 	printf("\n\nTime taken is %f", exec_time);

// 	return 0;
// }
