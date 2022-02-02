#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
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
  mint times = 2, pretimes = 1;
  vector<vector<mint>> dp(n, vector<mint>(2, 0));
  REP2(i, 1, n)
  {
    if (i == 1)
    {
      dp[i][0] = a[0] + a[1];
      dp[i][1] = a[0] - a[1];
    }
    else
    {
      if (i > 2)
      {
        mint tmp = times;
        times += pretimes;
        pretimes = tmp;
      }
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + a[i] * times;
      dp[i][1] = dp[i - 1][0] - a[i] * pretimes;
    }
  }

  //　n = 1 の時もある.
  if (n == 1)
  {
    dp[0][0] = a[0];
    dp[0][1] = 0;
  }

  mint b = dp[n - 1][0] + dp[n - 1][1];
  cout << b.val() << endl;
  return 0;
}