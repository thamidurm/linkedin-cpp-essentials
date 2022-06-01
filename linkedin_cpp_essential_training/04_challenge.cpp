#include <cstdio>

constexpr int PrimeCount = 25;

void printPrimes() 
{
	int primes[PrimeCount];
	
	primes[0] = 2;
	int count = 1;

	int primeCandidate = 3;
	bool isPrime;
	
	while (count < 25) 
	{
		isPrime = true;
		for (int i = 0; i < count; i++) 
		{
			if (!(primeCandidate % primes[i])) 
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime) 
		{
			primes[count++] = primeCandidate;
		}
		++primeCandidate;
	}

	for (auto i : primes)
	{
		printf("%d\n", i);
	}
}

//int main() 
//{
//	printPrimes();
//}