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
using VVV = vector<vector<vector<int>>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n;
  cin >> n;

  int a[3];
  cin >> a[0] >> a[1] >> a[2];

  sort(a, a + 3);

  int cnt = 0;
  VV dp(10000, V(3, 0));
  REPR(i, 3)
  {
    REP2(j, 1, n)
    {
      if (0 =< a[2] * dp[2] + a[1] * dp[1] + a[0] * dp[0])
      {
        dp[j][i] = dp[j - 1][i] + 1;
      }
      else if (0 == a[2] * dp[2] + a[1] * dp[1] + a[0] * dp[0])
      {
      }
    }
  }

  cout << cnt << endl;

  return 0;
}