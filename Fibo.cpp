#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long i, fibo, fibo1 = 0, fibo2 = 1;
	if (n == 1) fibo = 0;
	else if (n == 2) fibo = 1;
	else
	for (i = 0; i < n-2; i++)
	{

		fibo = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = fibo;

	}
	cout << fibo;
	return 0;
}
