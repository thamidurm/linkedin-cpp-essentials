#include <cstdio>

template<typename T>
T factorial(T n)
{
	if (n == 0)
		return 1;

	T result = n;
	while(n > 2)
	{
		result *= --n;
	}
	return result;
}

//int main() 
//{
//	int i = 5;
//	printf("%d! is %d\n", i, factorial(i));
//
//	long long unsigned int llui = 15;
//	printf("%lld! is %lld\n", llui, factorial(llui));
//
//	long double ld = 25;
//	printf("%.3Lf! is %-4.10Lg\n", ld, factorial(ld));
//}