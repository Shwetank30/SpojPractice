// Prime1.cpp : Generate all prime numbers between two given numbers.
// Two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000)
// 1,000,000,000 = 10^9 = 1 billion
//

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void sieveOfEratosthenes(int limit, vector<int>& prime) // 3, [3]
{
	// Create a boolean array "mark[0..n-1]" and initialize
	// all entries of it as true. A value in mark[p] will
	// finally be false if 'p' is Not a prime, else true.
	vector<bool> mark(limit + 1, true); // 4, T
	mark[0] = false;
	mark[1] = false;
	for (int p = 2; (p * p) <= limit; p++) // p = 4<3
	{
		// If p is not changed, then it is a prime
		if (mark[p])
		{
			// Update all multiples of p
			for (int i = p * p; i <= sqrt(limit); i += p)
				mark[i] = false;
		}
	}
	// Print all prime numbers and store them in prime
	for (int p = 2; p*p <= limit; p++) // 2<3
	{
		if (mark[p]) // 2
		{
			prime.push_back(p); //2
		}
	}
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int low, int high) // 3 5 
{
	if (low < 2 && high >= 2)
		low = 2;
	// Compute all primes smaller than or equal
	// to square root of n using simple sieve 
	vector<int> prime; 
	sieveOfEratosthenes(high, prime); // 3, size[3]
	int diff = high - low + 1;
	bool* mark = new bool[diff];
	memset(mark, true, sizeof(mark));

	
	for(int i : prime)
	{
		int lower = (low / i);

		if (lower <= 1)
			lower = i + i;
		else if (low % i)
			lower = (lower * i) + i;
		else
			lower = (lower * i);
		for (int j = lower; j <= high; j += i)
			mark[j - low] = false;
	}
	for (int i = low; i <= high; i++)
	{
		if (mark[i - low])
			cout << i << "\n";
	}
	
}
int main()
{
	int t,m,n; 
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n; // 3 5 
		segmentedSieve(m, n);
		cout << "\n";
	}
	return 0;
}


