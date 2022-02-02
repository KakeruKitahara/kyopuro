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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n, l;
  cin >> n >> l;

  vector<mint> dp(n + 1);
  dp[0] = 1;

  REP2(i, 1, n + 1)
  {
    if (i < l)
      dp[i] = dp[i - 1];
    else
      dp[i] = dp[i - 1] + dp[i - l];
  }

  cout << dp[n].val() << endl;
  return 0;
}