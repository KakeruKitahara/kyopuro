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
  int n, m;
  cin >> n >> m;
  V x(n);
  REP(i, n)
  {
    cin >> x[i];
  }

  map<int, int> y;
  REP(i, m)
  {
    int c, yy;
    cin >> c >> yy;
    y[c] = yy;
  }

  VVl dp(n, Vl(n + 1));

  if (y.count(1) == 0)
  {
    dp[0][1] = x[0];
  }
  else
  {
    dp[0][1] = x[0] + y[1];
  }

  REP2(i, 1, n)
  {
    REP(j, min(n + 1, i + 2))
    {
      if (j == 0)
      {
        REP(k, n + 1)
        {
          dp[i][0] = max(dp[i][0], dp[i - 1][k]);
        }
      }
      else
      {
        if (y.count(j) == 0)
        {
          dp[i][j] = dp[i - 1][j - 1] + x[i];
        }
        else
        {
          dp[i][j] = dp[i - 1][j - 1] + x[i] + y[j];
        }
      }
    }
  }
  ll ans = -1;
  REP(i, n + 1)
  {
    ans = max(dp[n - 1][i], ans);
  }

  cout << ans << endl;

  return 0;
}