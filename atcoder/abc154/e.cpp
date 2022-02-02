#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, k, cnt, len;

	cin >> n;
	cin >> k;

	int key = 1;

	len = 0;

	int m = n;
	while (m)
	{
		len++;
		m /= 10;
	}
	cnt = 0;

	for (int i = 1; i < len - k; i++)
	{
		key *= 10;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % key == 0)
		{
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}