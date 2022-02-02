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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n;
  ll l, w;
  cin >> n >> l >> w;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  Vl dist;
  dist.push_back(a[0]);
  REP2(i, 1, n)
  {
    if (a[i] - (a[i - 1] + w)> 0)
    {
      dist.push_back(a[i] - (a[i - 1] + w));
    }
  }

  if (l - (a[n - 1] + w) > 0)
  {
    dist.push_back(l - (a[n - 1] + w));
  }

  ll ans = 0;
  REP(i, dist.size())
  {
    ans += (dist[i] + (w - 1)) / w;
  }

  cout << ans << endl;
  return 0;
}