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
  int t;
  cin >> t;
  V l(t), r(t);
  REP(i, t)
  {
    cin >> l[i] >> r[i];
  }

  REP(i, t)
  {
    ll k = r[i] - 2 * l[i] + 1;
    if (k <= 0)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << k * (k + 1) / 2 << endl;
    }
  }

  return 0;
}