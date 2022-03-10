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
  int n;
  cin >> n;
  vector<vector<mint>> dp(n + 1, vector<mint>(10));

  REP2(i, 1, 10)
  {
    dp[1][i] = 1;
  }

  REP2(i, 1, n)
  {
    REP2(j, 1, 10)
    {
      if (j == 1)
      {
        dp[i + 1][j] = dp[i][j] + dp[i][j + 1];
      }
      else if (j == 9)
      {
        dp[i + 1][j] = dp[i][j] + dp[i][j - 1];
      }
      else
      {
        dp[i + 1][j] = dp[i][j] + dp[i][j + 1] + dp[i][j - 1];
      }
    }
  }

  mint ans = 0;

  REP2(i, 1, 10)
  {
    ans += dp[n][i];
  }

  cout << ans.val() << endl;


  return 0;
}