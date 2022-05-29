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
using mint = modint998244353;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<mint>> dp(n, vector<mint>(m));

  REP(i, m)
  {
    dp[0][i] = 1;
  }

  REP2(i, 1, n)
  {

    mint sum = 0;
    REP(j, m)
    {
      int sl = j - k;
      int sh = j + k;
      if (j == 0)
      {
        REP2(l, sh, m)
        {
          sum += dp[i - 1][l];
        }
        dp[i][j] = sum;
      }
      else
      {
        if (0 <= sl)
        {
          sum += dp[i - 1][sl];
        }
        if (sh <= m)
        {
          sum -= dp[i - 1][sh - 1];
        }
        dp[i][j] = sum;
      }
    }
  }

  mint ans = 0;

  REP(i, m)
  {
    ans += dp[n - 1][i];
  }

  cout << ans.val() << endl;

  return 0;
}