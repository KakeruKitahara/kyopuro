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
  Vl x(q);
  REP(i, q)
  {
    cin >> x[i];
  }

  sort(a.begin(), a.end());
  Vl s(n);
  s[0] = a[0];
  REP2(i, 1, n)
  {
    s[i] = s[i - 1] + a[i];
  }

  REP(i, q)
  {
    ll ans = 0;
    auto it = lower_bound(a.begin(), a.end(), x[i]);
    int p = it - a.begin();
    ll t = 0;
    if (p != 0)
    {
      t = s[p - 1];
    }
    else
    {
      t = 0;
    }
    ans += abs(s[n - 1] - t - (n - p) * x[i]);
    ans += abs(t - p * x[i]);
    cout << ans << endl;
  }

  return 0;
}