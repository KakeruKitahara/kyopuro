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
  int n, k;
  cin >> n >> k;

  V a(k);
  REP(i, k)
  {
    cin >> a[i];
    a[i]--;
  }
  Vl x(n), y(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }
  double ans = -1;

  Vl b;

  REP(i, n)
  {
    int cnt = 0;
    REP(j, k)
    {
      if (i != x[j])
      {
        cnt++;
      }
    }
    if (cnt == k)
    {
      b.push_back(i);
    }
  }
  REP(i, b.size())
  {
    double maxs = IINF;

    REP(j, k)
    {

      double dis = sqrt((x[b[i]] - x[a[j]]) * (x[b[i]] - x[a[j]]) + (y[b[i]] - y[a[j]]) * (y[b[i]] - y[a[j]]));
      maxs = min(dis, maxs);
    }
    ans = max(maxs, ans);
  }

  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}