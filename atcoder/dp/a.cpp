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
using namespace std;

int main()
{
  int n;
  cin >> n;
  int h[n];
  REP(i, n)
  {
    cin >> h[i];
  }
  int dp[n];
  dp[0] = 0;
  REP2(i, 1, n)
  {
    if (2 <= i)
    {
      dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    else
    {
      dp[i] = abs(h[i] - h[i - 1]);
    }
  }

  cout << dp[n - 1] << endl;

  return 0;
}