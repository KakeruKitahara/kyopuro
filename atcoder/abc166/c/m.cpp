#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, flag = 0;
	cin >> n >> m;
	int cnt[n + 1] = {};

	int h[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		cin >> h[i];
	}

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (h[a] > h[b])
		{
			cnt[b] = 1;
		}
		else if (h[b] > h[a])
		{
			cnt[a] = 1;
		}
		else
		{
			cnt[a] = 1;
			cnt[b] = 1;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (cnt[i] == 0)
			{
				flag++;
			}
	}

	cout << flag;
	return 0;
}