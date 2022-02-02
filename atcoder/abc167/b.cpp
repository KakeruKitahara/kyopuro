#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, k;
	int i = 0;
	int sum = 0;
	cin >> a >> b >> c >> k;

	for (; i < k && a != 0; i++)
	{
		sum++;
		a--;
	}
	if (k == i)
	{
		cout << sum;
		return 0;
	}
	for (; i < k && b != 0; i++)
	{
		b--;
	}
	if (i == k)
	{
		cout << sum;
		return 0;
	}
	for (; i < k && c != 0; i++)
	{
		sum--;
		c--;
	}
	cout << sum;

	return 0;
}