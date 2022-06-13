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

int main()
{
  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d >= 0)
  {
    ll s = a;
    ll t = a + (n - 1) * d;

    if (x <= s)
    {
      cout << s - x << endl;
      return 0;
    }
    else if (t <= x)
    {
      cout << x - t << endl;
      return 0;
    }
    else
    {
      ll y = x - a;

      cout << min(abs(y - ((y + d - 1) / d - 1) * d), abs(((y + d - 1) / d) * d - y)) << endl;
    }
  }
  else
  {
    ll t = a;
    ll s = a + (n - 1) * d;

    if (x <= s)
    {
      cout << s - x << endl;
      return 0;
    }
    else if (t <= x)
    {
      cout << x - t << endl;
      return 0;
    }
    else
    {
      ll y = x - a;

      cout << min(abs(y - ((y + d - 1) / d - 1) * d), abs(((y + d - 1) / d) * d - y)) << endl;
    }
  }

  return 0;
}