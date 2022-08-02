#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;

int main()
{
  int n, w;
  cin >> n >> w;
  int w2[n], v[n];
  REP(i, n)
  {
    cin >> w2[i] >> v[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(w + 1, 0));
  REP(i, n)
  {
    REPR(j, w + 1)
    {
      if (i > 0)
      {
        if (j - w2[i] >= 0)
        {
          dp[i][j] = max(dp[i - 1][j - w2[i]] + v[i], dp[i - 1][j]);
        }
        else{
          dp[i][j] = dp[i - 1][j];
        }
      }
      else
      {
        if (j - w2[i] >= 0)
        {
          dp[i][j] = v[i];
        }
      }
    }
  }

  cout << dp[n - 1][w] << endl;
  return 0;
}
