#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n - 1], ans[n + 1] = {};
	REP(i, n - 1)
	{
		cin >> a[i];
		ans[a[i]]++;
	}

	REP2(i, 1, n + 1)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}