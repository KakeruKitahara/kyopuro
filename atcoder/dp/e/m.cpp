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
  int n, w;
  cin >> n >> w;
  V w2(n), v(n);
  REP(i, n)
  {
    cin >> w2[i] >> v[i];
  }

  VV dp(n, V(100001, IINF));

  REP(i, n)
  {
    if (i == 0)
    {
      REP(j, n)
      {
        dp[j][0] = 0;
      }
      dp[0][v[0]] = w2[0];
      continue;
    }
    REP(j, 100001)
    {
      if (0 <= j - v[i])
      {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w2[i]);
      }
      else{
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  int ans = 0;
  REP(j, 100001)
  {
    if (dp[n - 1][j] <= w)
    {
      ans = j;
    }
  }

  cout << ans << endl;

  return 0;
}