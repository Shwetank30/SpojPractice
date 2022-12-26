#include <vcruntime_string.h>
#include <iostream>
using namespace std;

void SieveOfEratosthenes(int num)
{
	bool *pno = new bool[num + 1];
	memset(pno, true, num+1);
	for (int i = 2; i*i <= num; i++)
	{
		if (pno[i] == true)
		{
			for (int j = i * 2; j <= num; j += i)
				pno[j] = false;
		}
	}
	for (int i = 2; i <= num; i++)
		if (pno[i])
			cout << i << " ";
	delete[] pno;
}

int main()
{
	int num = 15;
	cout << "The prime numbers smaller or equal to " << num << " are: ";
	SieveOfEratosthenes(num);
	return 0;
}