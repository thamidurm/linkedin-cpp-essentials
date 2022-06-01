#include <cstdio>

long long int factorial(int n) 
{
	if (n == 0)
		return 1;

	long long int result = n;
	while (n > 2) 
	{
		result *= --n;
	}
	return result;
}

//int main() 
//{
//	long long int n = 3;
//	printf("Factorial of %lld, %lld! = %lld", n, n, factorial(n));
//}