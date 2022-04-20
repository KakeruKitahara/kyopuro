#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

ll f(ll a, ll b)
{
	return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main()
{
	ll n;
	cin >> n;

	int a = 0;
	ll ans = LINF;

	REP(a, 1000001)
	{
		ll l = -1, r = 1000001;
		ll b;
		while (r - l > 1)
		{
			b = (l + r) / 2;
			if (n == f(a, b))
			{
				break;
			}
			else if (n < f(a, b))
			{
				r = b;
			}
			else
			{
				l = b;
			}
		}
		if (f(a, b) < n)
		{
			b++;
		}

		ans = min(ans, f(a, b));
	}

	cout << ans << endl;
}