#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define TIME(function)	start = clock();											\
						function;													\
						end = clock();												\
						cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC	\


int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

int	main(void)
{
	long long res;
//	clock_t start, end;
//	double cpu_time_used;

/* ex00 - iterative factorial */

	printf("ex00 :\n");
	if ((res = ft_iterative_factorial(6)) == 720)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_iterative_factorial(0)) == 1)
		printf("OK | ");
	else
		printf("KO | ");
	if (!(res = ft_iterative_factorial(-5)))
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

/* ex01 - recursive factorial */

	printf("\nex01 :\n");
	if ((res = ft_recursive_factorial(6)) == 720)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_recursive_factorial(0)) == 1)
		printf("OK | ");
	else
		printf("KO | ");
	if (!(res = ft_recursive_factorial(-5)))
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

/* ex02 - iterative power */

	printf("\nex02 :\n");
	if ((res = ft_iterative_power(2, 8)) == 256)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_iterative_power(4, -5)) == 0)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_iterative_power(0, 0)) == 1)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_iterative_power(-2, 0)) == 1)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_iterative_power(-25, 3)) == -15625)
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

	/* ex03 - recursive power */

	printf("\nex03 :\n");
	if ((res = ft_recursive_power(2, 8)) == 256)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_recursive_power(4, -5)) == 0)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_recursive_power(0, 0)) == 1)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_recursive_power(-2, 0)) == 1)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_recursive_power(-25, 3)) == -15625)
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

	/* ex04 - fibonacci */

	printf("\nex04 :\n");
	if ((res = ft_fibonacci(16)) == 987)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_fibonacci(-5)) == -1)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_fibonacci(0)) == 0)
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

	/* ex05 - square root */
	
	printf("\nex05 :\n");
	if ((res = ft_sqrt(2089586944)) == 45712)
		printf("OK | ");
	else
		printf("KO | ");
	if (!(res = ft_sqrt(-5)))
		printf("OK | ");
	else
		printf("KO | ");
	if (!(res = ft_sqrt(15478)))
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

	/* ex06 - is prime */

	printf("\nex06 :\n");
	if ((res = ft_is_prime(-5)) == 0)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_is_prime(2)) == 1)
		printf("OK | ");
	else
		printf("KO |");
	if ((res = ft_is_prime(83)) == 1)
		printf("OK | ");
	else
		printf("KO |");
	if ((res = ft_is_prime(961)) == 0)
		printf("OK | ");
	else
		printf("KO |");
	if ((res = ft_is_prime(24660)) == 0)
		printf("OK | ");
	else
		printf("KO |");
	if ((res = ft_is_prime(2147483647)) == 1)
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");

	/* ex07 - find next prime */

	printf("\nex07 :\n");
	if ((res = ft_find_next_prime(-2147483648)) == 2)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_find_next_prime(-5)) == 2)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_find_next_prime(10195)) == 10211)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_find_next_prime(3)) == 3)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_find_next_prime(90)) == 97)
		printf("OK | ");
	else
		printf("KO | ");
	if ((res = ft_find_next_prime(2147483630)) == 2147483647)
		printf("OK");
	else
		printf("KO");
	printf("\n---------------\n");

	/* ex08 - ten queens puzzle */

/*	printf("\nex08 :\n");
	TIME(res = ft_ten_queens_puzzle());
	if (cpu_time_used < 10)
		printf("OK | ");
	else
		printf("KO | ");
	if (res == 724)
		printf("OK");
	else
		printf("KO");
	printf("\n---------------");*/
}
