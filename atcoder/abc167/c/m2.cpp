#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int dfs(int pos, int n, int m, bool boo[], vector<V> a, int x, int c[])
{
	if (pos == n)
	{
		int sum;
		REP(i, m)
		{
			sum = 0;
			REP(j, n)
			{
				sum += a[j][i] * boo[j];
			}
			if (sum < x)
				return 1E+8;
		}
		sum = 0;
		REP(i, n)
		{
			sum += c[i] * boo[i];
		}
		return sum;
	}

	boo[pos] = true;
	int l = dfs(pos + 1, n, m, boo, a, x, c);
	boo[pos] = false;
	int r = dfs(pos + 1, n, m, boo, a, x, c);

	return min(l, r);
}

int main()
{
	int n, m, x;
	cin >> n >> m >> x;

	int c[n];
	vector<V> a(n, V(m));

	REP(i, n)
	{
		cin >> c[i];
		REP(j, m)
		{
			cin >> a[i][j];
		}
	}

	bool boo[n] = {};
	int ans = dfs(0, n, m, boo, a, x, c);

	if (ans == 1E+8)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << ans << endl;
	}

	return 0;
}