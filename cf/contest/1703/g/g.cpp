#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
  int n, k;
  cin >> n >> k;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  ll sum = 0;
  ll ans = 0;
  int maxs = 0;
  REP(i, n)
  {
    sum += (a[i] + 1) / 2;
    maxs = max(a[i], maxs);
  }
  int j = n;
  REP(i, n)
  {
    if (k < sum)
    {
      ans += a[i];
      ans -= k;
      sum -= (a[i] + 1) / 2;
    }
    else
    {
      j = i;
      break;
    }
  }
  ll x = 2;
  for (j; j < n; j++)
  {
    ans += a[j] / x;
    if (x > maxs)
    {
      x = LINF;
    }
    if (x != LINF)
    {
      x *= 2;
    }
  }

  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}