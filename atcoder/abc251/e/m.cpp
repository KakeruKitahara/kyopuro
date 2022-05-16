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
  V a(n);

  REP(i, n)
  {
    cin >> a[i];
  }

  VV dpon(n, V(2));
  VV dpoff(n, V(2));
  dpon[0][0] = a[0];
  dpoff[0][1] = a[n - 1];

  dpon[1][0] = dpon[0][0] + a[1];
  dpon[1][1] = dpon[0][0];
  REP2(i, 2, n)
  {
    dpon[i][0] = min(dpon[i - 1][0] + a[i], dpon[i - 1][1] + a[i]);
    dpon[i][1] = min(dpon[i - 1][0], dpon[i - 1][1] + a[i - 1]);
  }

  dpoff[1][0] = dpoff[0][1] + a[1];
  dpoff[1][1] = dpoff[0][1] + a[0];
  REP2(i, 2, n - 1)
  {
    dpoff[i][0] = min(dpoff[i - 1][0] + a[i], dpoff[i - 1][1] + a[i]);
    dpoff[i][1] = min(dpoff[i - 1][0], dpoff[i - 1][1] + a[i - 1]);
  }
  dpoff[n - 1][0] = min(dpoff[n - 2][0], dpoff[n - 2][1]);
  dpoff[n - 1][1] = min(dpoff[n - 2][0], dpoff[n - 2][1] + a[n - 2]);

  cout << min(dpoff[n - 1][1], min(dpon[n - 1][0], dpon[n - 1][1])) << endl;

  return 0;
}
