// Prime1.cpp : Generate all prime numbers between two given numbers.
// Two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000)
// 1,000,000,000 = 10^9 = 1 billion
//

#include <iostream>
using namespace std;

int main()
{
	long t,m,n,ctr;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n;
		for (long p = m; p <= n; p++)
		{
			ctr = 0;
			for (int j = 2; j < p; j++) {
				if (p % j == 0) {
					ctr++;
					break;
				}
			}
			if (ctr == 0 && p != 1) {
				cout << p << '\n';
			}
		}
		cout << "\n";
	}
	
}


