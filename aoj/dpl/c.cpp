#include <bits/stdc++.h>
using namespace std;
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

int main()
{
  int n, w;
  cin >> n >> w;
  V v(n), w2(n);
  REP(i, n)
  {
    cin >> v[i] >> w2[i];
  }

  VV dp(n, V(w + 1));
  REP(i, n)
  {
    REP(j, w + 1)
    {
      if (i == 0 && w2[0] <= j)
      {
        dp[0][j] = dp[0][j - w2[0]] + v[0];
      }
      if (i > 0)
      {
        if (w2[i] <= j)
          dp[i][j] = max(dp[i][j - w2[i]] + v[i], dp[i - 1][j]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n - 1][w] << endl;
  return 0;
}