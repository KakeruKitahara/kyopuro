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
constexpr int INF = 1000000000 + 8;

int main()
{
  int n;
  cin >> n;
  int h[n];
  REP(i, n)
  {
    cin >> h[i];
  }

  int dp[n + 1];

  REP(i, n + 1)
  {
    dp[i] = INF;
  }

  REP2(i, 1, n + 1)
  {
    if (i >= 3)
      dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i - 2]), dp[i - 2] + abs(h[i - 1] - h[i - 3]));
    else if (i == 2)
      dp[i] = dp[i - 1] + abs(h[i - 1] - h[i - 2]);
    else
      dp[i] = 0;
  }

  cout << dp[n] << endl;

  return 0;
}