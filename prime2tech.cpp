// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so


#include <bitset>
#include <iostream>
using namespace std;

bitset<500001> Primes;
void SieveOfEratosthenes(int n)
{
	Primes[0] = 1;
	for (int i = 3; i <= n; i += 2) {
		if (Primes[i / 2] == 0) {
			for (int j = 3 * i; j <= n; j += 2 * i)   //to jump through member for the 3 multiples or similar multiples
				Primes[j / 2] = 1;
		}
	}
}

int main()
{
	int n = 100;
	SieveOfEratosthenes(n);
	for (int i = 1; i <= n; i++) {
		if (i == 2)
			cout << i << ' ';
		else if (i % 2 == 1 && Primes[i / 2] == 0)
			cout << i << ' ';
	}
	return 0;
}
