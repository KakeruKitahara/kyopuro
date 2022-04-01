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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);

  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }

  vector<vector<ll>> dp(n, vector<ll>(2));
  dp[0][0] = 1;
  dp[0][1] = 1;

  REP(i, n - 1)
  {

    if (abs(a[i + 1] - a[i]) <= k)
    {
      dp[i + 1][0] = max(dp[i][0], dp[i + 1][0]);
    }
    if (abs(a[i + 1] - b[i]) <= k)
    {
      dp[i + 1][0] = max(dp[i][1], dp[i + 1][0]);
    }
    if (abs(b[i + 1] - a[i]) <= k)
    {
      dp[i + 1][1] = max(dp[i][0], dp[i + 1][1]);
    }
    if (abs(b[i + 1] - b[i]) <= k)
    {
      dp[i + 1][1] = max(dp[i][1], dp[i + 1][1]);
    }
  }

  if (1 <= dp[n - 1][0] + dp[n - 1][1])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}