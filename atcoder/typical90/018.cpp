#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
const double PI = 3.14159265358979323846;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int t;
  cin >> t;
  int l;
  ll x, y;
  cin >> l >> x >> y;
  int q;
  cin >> q;
  V e(q);
  REP(i, q)
  {
    cin >> e[i];
  }

  double theta = 2.0 * PI / t;

  REP(i, q)
  {
    double p_z = (1 - cos(e[i] * theta)) * l / 2.0;
    double p_y = -sin(e[i] * theta) * l / 2.0;

    double dist1 = sqrt((p_y - y) * (p_y - y) + (double)x * x); // 2乗の時はオーバーフローに注意.
    printf("%.12f\n", atan2(p_z, dist1) * 180 / PI);
  }

  return 0;
}