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
  int n, x;
  cin >> n >> x;
  V a(n), b(n);
  REP(i, n)
  {
    cin >> a[i] >> b[i];
  }

  VV dp(n, V(10001));

  REP(i, n)
  {
    REP(j, 10001)
    {
      if (i == 0)
      {
        dp[0][a[0]] = 1;
        dp[0][b[0]] = 1;
      }
      else
      {
        if (a[i] <= j)
        {
          dp[i][j] = dp[i - 1][j - a[i]];
        }
        if (b[i] <= j)
        {
          dp[i][j] = dp[i - 1][j - b[i]];
        }
        if (a[i] <= j && b[i] <= j)
        {
          dp[i][j] = max(dp[i - 1][j - a[i]], dp[i - 1][j - b[i]]);
        }
      }
    }
  }

  if (dp[n - 1][x] == 1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}