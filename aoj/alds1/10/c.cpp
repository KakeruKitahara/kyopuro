#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;

int main()
{
  int q;
  cin >> q;
  vector<S> x(q), y(q);
  REP(i, q)
  {
    cin >> x[i] >> y[i];
  }

  REP(i, q)
  {
    VV dp(x[i].size() + 1, V(y[i].size() + 1));
    REP(j, x[i].size())
    {
      REP(k, y[i].size())
      {
        if (x[i][j] == y[i][k])
        {
          dp[j + 1][k + 1] = max(dp[j][k + 1], max(dp[j + 1][k], dp[j][k] + 1));
        }
        else
        {
          dp[j + 1][k + 1] = max(dp[j][k + 1], dp[j + 1][k]);
        }
      }
    }
    cout << dp[x[i].size()][y[i].size()] << endl;
  }
  return 0;
}