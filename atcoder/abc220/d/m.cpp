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
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  vector<vector<mint>> dp(n, vector<mint>(10));

  dp[0][a[0]] = 1;
  REP(i, n - 1)
  {
    REP(j, 10)
    {
      dp[i + 1][(j + a[i + 1]) % 10] += dp[i][j];
      dp[i + 1][(j * a[i + 1]) % 10] += dp[i][j];
    }
  }

  REP(i, 10)
  {
    cout << dp[n - 1][i].val() << endl;
  }

  return 0;
}