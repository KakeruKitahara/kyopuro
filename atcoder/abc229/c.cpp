#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> a(n);
  REP(i, n)
  {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.rbegin(), a.rend());

  ll ans = 0;
  REP(i, n)
  {
    if (w - a[i].second >= 0)
    {
      ans += a[i].first * a[i].second;
      w -= a[i].second;
    }
    else
    {
      ans += a[i].first * w;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}