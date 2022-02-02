#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n - 1; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;

int main()
{
  int n, m;
  cin >> n >> m;
  V a(m), b(m), c(m);
  REP(i, m)
  {
    cin >> a[i] >> b[i] >> c[i];
  }

  VV dp(n + 1, V(n + 1, INF));
  ll sum = 0;

  REP(i, m)
  {
    dp[a[i]][b[i]] = c[i];
  }
  REP2(j, 1, n + 1)
  {
    REP2(k, 1, n + 1)
    {
      if (dp[j][k] != INF)
      {
        sum += dp[j][k];
      }
      cout << dp[j][k] << " ";
    }
    cout << endl;
  }
  cout << endl;
  REP(i, n - 1)
  {
    REPR2(j, n - 1, 1)
    {
      REP2(k, 1, n + 1)
      {
        if (j != k)
        {
          REP2(s, 1, n + 1)
          {
            if (dp[j][s] != INF || dp[j][s] != INF)
            {
              dp[j][k] = min(dp[j][s] + dp[s][k], dp[j][k]);
            }
          }
        }
      }
    }
    REP2(j, 1, n + 1)
    {
      REP2(k, 1, n + 1)
      {
        if (dp[j][k] != INF)
        {
          sum += dp[j][k];
        }
        cout << dp[j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  cout << sum << endl;
  return 0;
}