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


  vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));

  dp[0][0] = 1;

  REP(i, n)
  {
    REP(l, k)
    {
      REP(j, m)
      {
        if (l + j + 1<= k)
        {
          dp[i + 1][l + j + 1] += dp[i][l];
        }
      }
    }
  }

  mint ans = 0;
  REP(i, k + 1)
  {
    ans += dp[n][i];
  }

  cout << ans.val() << endl;

  return 0;
}