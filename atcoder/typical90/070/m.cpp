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
  int n;
  cin >> n;
  Vl x(n), y(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll sumx = 0;

  ll minx = x[0], miny = y[0];

  REP(i, n)
  {
    x[i] -= minx;
    sumx += x[i];
  }
  sumx -= x[0];

  ll sumy = 0;
  REP(i, n)
  {
    y[i] -= miny;
    sumy += y[i];
  }
  sumy -= y[0];

  ll ans = sumy + sumx;
  REP(i, n - 1)
  {
    sumx += (-n + 2 + 2 * i) * (x[i + 1] - x[i]);
    sumy += (-n + 2 + 2 * i) * (y[i + 1] - y[i]);
    ans = min(ans, sumy + sumx);
  }

  cout << ans << endl;

  return 0;
}