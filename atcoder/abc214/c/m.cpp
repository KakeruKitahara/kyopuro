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
  int n;
  cin >> n;
  vector<pair<ll, ll>> ts(n);
  for (int i = 0; i < n; i++)
  {
    cin >> ts[i].second;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> ts[i].first;
  }

  ll mins = ts[0].first, index = 0;
  REP(i, n)
  {
    if (mins > ts[i].first)
    {
      mins = ts[i].first;
      index = i;
    }
  }

  vector<ll> ans(n);
  ans[index] = ts[index].first;

  REP2(i, index + 1, n)
  {
    if (i == 0)
    {
      ans[i] = min(ans[n - 1] + ts[n - 1].second, ts[i].first);
    }
    else
    {
      ans[i] = min(ans[i - 1] + ts[i - 1].second, ts[i].first);
    }
  }
  REP(i, index)
  {
    if (i == 0)
    {
      ans[i] = min(ans[n - 1] + ts[n - 1].second, ts[i].first);
    }
    else
    {
      ans[i] = min(ans[i - 1] + ts[i - 1].second, ts[i].first);
    }
  }

  REP(i, n)
  {
    cout << ans[i] << endl;
  }
  return 0;
}