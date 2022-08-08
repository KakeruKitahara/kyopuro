#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

/* pair operator */
template <class X>
pair<X, X> operator+(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first + ob2.first;
  res.second = ob1.second + ob2.second;
  return res;
}

template <class X>
pair<X, X> operator-(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first - ob2.first;
  res.second = ob1.second - ob2.second;
  return res;
}

template <class X>
pair<X, X> operator*(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first * ob2.first;
  res.second = ob1.second * ob2.second;
  return res;
}

template <class X>
pair<X, X> operator/(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first / ob2.first;
  res.second = ob1.second / ob2.second;
  return res;
}

int main()
{
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  V a(n), b(n);
  REP(i, n)
  {
    cin >> a[i] >> b[i];
  }
  VVV dp(n, VV(301, V(301, IINF)));

  REP(i, n)
  {
    dp[i][0][0] = 0;
    if (i == 0)
    {

      dp[0][a[0]][b[0]] = 1;
    }
    else
    {
      REP(j, 301)
      {
        REP(k, 301)
        {
          dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j][k]);
          int jn = min(300, j + a[i]), kn = min(300, k + b[i]);
          if (jn == 300 | kn == 300)
          {
            dp[i][jn][kn] = min(dp[i - 1][jn][kn], min(dp[i - 1][j][k] + 1, dp[i][jn][kn]));
          }
          else
          {
            dp[i][jn][kn] = min(dp[i - 1][jn][kn], dp[i - 1][j][k] + 1);
          }
        }
      }
    }
  }

  int ans = IINF;
  REP2(j, x, 301)
  {
    REP2(k, y, 301)
    {
      ans = min(ans, dp[n - 1][j][k]);
    }
  }
  if (ans == IINF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
  return 0;
}