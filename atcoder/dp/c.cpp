#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  REP(i, n)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  int dp[3][n];
  dp[0][0] = a[0];
  dp[1][0] = b[0];
  dp[2][0] = c[0];
  REP2(j, 1, n)
  {
    dp[0][j] = max(dp[1][j - 1], dp[2][j - 1]) + a[j];
    dp[1][j] = max(dp[0][j - 1], dp[2][j - 1]) + b[j];
    dp[2][j] = max(dp[0][j - 1], dp[1][j - 1]) + c[j];
  }

  int ans = -1;
  REP(i, 3)
  {
    ans = max(ans, dp[i][n - 1]);
  }

  cout << ans <<endl;
  return 0;
}