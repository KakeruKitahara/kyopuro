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

ll max(ll a, ll b)
{
  return a > b ? a : b;
}

int main()
{
  int t;
  cin >> t;
  vector<ll> n2(t), n3(t), n4(t);

  REP(i, t)
  {
    cin >> n2[i] >> n3[i] >> n4[i];
  }

  REP(i, t)
  {
    ll ans = 0;
    if (n3[i] / 2 > 0 && n4[i] > 0)
    {
      if (n3[i] / 2 > n4[i])
      {
        ans += n4[i];
        n3[i] -= n4[i] * 2;
      }
      else
      {
        ans += n3[i] / 2;
        n4[i] -= n3[i] / 2;
      }
    }
    if (n2[i] > 0 && n3[i] > 0)
    {
      if (n3[i] > n2[i])
      {
        ans += n2[i] / 2;
        n3[i] -= n2[i];
      }
      else
      {
        ans += n2[i] / 2;
        n2[i] -= n3[i];
      }
    }
    if (n4[i] / 2 > 0 && n2[i] > 0)
    {
      if (n4[i] / 2 > n2[i])
      {
        ans += n2[i];
        n2[i] = 0;
      }
      else
      {
        ans += n4[i] / 2;
        n2[i] -= n4[i] / 2;
      }
    }
    ans += n2[i] / 5;
    cout << ans << endl;
  }

  return 0;
}