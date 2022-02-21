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
  vector<ll> a(46, 0), b(46, 0), c(46, 0);
  int ta, tb, tc;
  REP(i, n)
  {
    cin >> ta;
    a[ta % 46]++;
  }
  REP(i, n)
  {
    cin >> tb;
    b[tb % 46]++;
  }
  REP(i, n)
  {
    cin >> tc;
    c[tc % 46]++;
  }

  ll ans = 0;
  REP(i, 46)
  {
    REP(j, 46)
    {
      REP(k, 46)
      {
        if (!((i + k + j) % 46))
        {
          ans += (a[i] * b[j] * c[k]);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}