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
  ll ans = n * (n - 1) * (n - 2) / 6;

  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      REP2(k, j + 1, n)
      {
        ll x1 = x[i] - x[j];
        ll x2 = x[j] - x[k];
        ll y1 = y[i] - y[j];
        ll y2 = y[j] - y[k];
        if (x1 * y2 == x2 * y1)
        {
          ans--;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}