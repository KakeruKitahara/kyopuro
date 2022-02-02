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
  int n, q;
  cin >> n >> q;
  vector<ll> l(q), r(q), v(q), a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, q)
  {
    cin >> l[i] >> r[i] >> v[i];
    l[i]--;
    r[i]--;
  }
  ll sum = 0;
  REP(i, n - 1)
  {
    sum += abs(a[i] - a[i + 1]);
  }

  REP(i, q)
  {
    if (l[i] == 0 && r[i] == n - 1)
    {
      // pass
    }
    else if (l[i] == 0)
    {
      sum -= abs(a[r[i]] - a[r[i] + 1]);
      a[r[i]] += v[i];
      sum += abs(a[r[i]] - a[r[i] + 1]);
    }
    else if (r[i] == n - 1)
    {
      sum -= abs(a[l[i] - 1] - a[l[i]]);
      a[l[i]] -= v[i];
      sum += abs(a[l[i] - 1] - (a[l[i]]));
    }
    else
    {
      sum -= abs(a[r[i]] - a[r[i] + 1]);
      a[r[i]] += v[i];
      sum += abs(a[r[i]] - a[r[i] + 1]);
      sum -= abs(a[l[i] - 1] - a[l[i]]);
      a[l[i]] -= v[i];
      sum += abs(a[l[i] - 1] - (a[l[i]]));
    }
    cout << sum << endl;
  }
  return 0;
}