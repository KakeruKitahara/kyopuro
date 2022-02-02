#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[m];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	int sum, b;
	sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += a[i];
	}
	b = n - sum;
	if (b < 0)
	{
		b = -1;
	}
	cout << b;
	return 0;
}