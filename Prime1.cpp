// Prime1.cpp : Generate all prime numbers between two given numbers.
// Two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000)
// 1,000,000,000 = 10^9 = 1 billion
//

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;


// Prints all prime numbers between 'low' & 'high'
void segmentedSieve(int low, int high) // 3 5 
{
	int lim = sqrt(high);
	vector<bool> mark(lim + 1, false);
	vector<int> primes;
	for (int i = 2; i <= lim; i++)
	{
		if (!mark[i])
		{
			primes.emplace_back(i);
			for (int j = i * i; j <= lim; j += i)
				mark[j] = true;
		}
	}

	vector<bool> isPrime(high - low + 1, true);
	for (int i : primes)
		for (int j = max(i * i, (low + i - 1) / i * i); j <= high; j += i)
			isPrime[j - low] = false;
	if (low == 1)
		isPrime[0] = false;
	for (int k = 0; k < isPrime.size(); k++)
		if(isPrime[k])
			cout << low+k << '\n';
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


