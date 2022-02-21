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
  int n, m, l, x;
  cin >> n >> m >> l >> x;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  VV dp(n + 1, V(m, IINF));

  REP(i, n)
  {
    REP(j, m)
    {
      if (i == 0)
      {
        dp[i][a[i] % m] = a[i];
        break;
      }
      if (j == 0)
      {
        dp[i][a[i] % m] = a[i];
      }
      else
      {
        int t = (j < a[i]) ? m + (j - a[i]) % m : j - a[i];
        dp[i][j] = min(dp[i - 1][t] + a[i], dp[i - 1][j]);
      }
    }
  }
  S o = ((dp[n - 1][l] / m) < x) ? "Yes" : "No";
  cout << o << endl;

  return 0;
}