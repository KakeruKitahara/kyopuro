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
  P x0, xn;
  cin >> x0.first >> x0.second;
  cin >> xn.first >> xn.second;
  pair<double, double> o, ans;
  o.first = (x0.first + xn.first) / 2.0;
  o.second = (x0.second + xn.second) / 2.0;
  double pi = M_PI;
  ans.first = (x0.first - o.first) * cos(2 * pi / n) - (x0.second - o.second) * sin(2 * pi / n);
  ans.second = (x0.first - o.first) * sin(2 * pi / n) + (x0.second - o.second) * cos(2 * pi / n);

  cout << fixed << setprecision(6) << ans.first + o.first << " " << ans.second + o.second << endl;
  return 0;
}