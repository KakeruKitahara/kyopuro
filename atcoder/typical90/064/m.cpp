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
  int n, q;
  cin >> n >> q;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  Vl l(q), r(q), v(q);
  REP(i, q)
  {
    cin >> l[i] >> r[i] >> v[i];
    l[i]--;
    r[i]--;
  }

  Vl sa(n - 1);

  REP(i, n - 1)
  {
    sa[i] = a[i + 1] - a[i];
  }

  ll ans = 0;

  REP(i, n - 1)
  {
    ans += abs(sa[i]);
  }

  REP(i, q)
  {
    if (l[i] != 0)
    {
      ans -= abs(sa[l[i] - 1]);
      sa[l[i] - 1] += v[i];
      ans += abs(sa[l[i] - 1]);
    }
    if (r[i] != n - 1)
    {
      ans -= abs(sa[r[i]]);
      sa[r[i]] -= v[i];
      ans += abs(sa[r[i]]);
    }

    cout << ans << endl;
  }

  return 0;
}