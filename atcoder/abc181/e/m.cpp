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
  int n, m;
  cin >> n >> m;
  V h(n), w(m);
  REP(i, n)
  {
    cin >> h[i];
  }
  REP(i, m)
  {
    cin >> w[i];
  }

  sort(h.begin(), h.end());

  Vl sum(n);
  sum[0] = -h[0];
  REP2(i, 1, n)
  {
    if (i % 2 == 0)
    {
      sum[i] = sum[i - 1] - h[i];
    }
    else
    {
      sum[i] = sum[i - 1] + h[i];
    }
  }
  ll ans = LINF;
  REP(i, m)
  {
    auto k = lower_bound(h.begin(), h.end(), w[i]);
    int idx = k - h.begin();
    ll res = 0;
    if (h.begin() == k)
    {
      res += -sum[n - 1];
    }
    else if (h.end() == k)
    {
      res += sum[n - 1];
    }
    else
    {
      res += -(sum[n - 1] - sum[idx - 1]);
      res += sum[idx - 1];
    }

    if (idx % 2 == 0)
    {
      res += -w[i];
    }
    else
    {
      res += w[i];
    }

    ans = min(ans, res);
  }

  cout << ans << endl;

  return 0;
}