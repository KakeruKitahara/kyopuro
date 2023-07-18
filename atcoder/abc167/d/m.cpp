#include <bits/stdc++.h>

using namespace std;


#define N 200000
int main()
{
	long long int k;
	int n;
	cin >> n >> k;
	int a[n];
	int trace[2][N] = {};
	int cnt;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int pnt = 1;

	for (int i = 0; i < k; i++)
	{
		pnt = a[pnt - 1];
		trace[0][pnt]++;
		if (trace[0][pnt] == 2)
		{
			k %= trace[1][pnt];
			break;
		}
		if (trace[0][pnt] == 1)
		{
			trace[1][pnt]++;
		}
		for (int j = 0; j < n; j++)
		{
			if (trace[0][j] == 1)
			{
				trace[1][j]++;
			}
		}
	}

	for (int i = 0; i < k; i++)
	{
		pnt = a[pnt - 1];
	}

	cout << pnt << endl;
	return 0;
}