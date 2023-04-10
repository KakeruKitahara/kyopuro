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
  S s;
  cin >> s;

  reverse(s.begin(), s.end());

  V d(s.size());
  vector<vector<mint>> dp(s.size(), vector<mint>(13, 0));

  d[0] = 0;
  d[1] = 10;
  REP2(i, 2, s.size())
  {
    d[i] = (d[i - 1] * 10) % 13;
  }

  dp[0][s[0] - '0'][s[0] - '0'] = 1;
  REP2(i, 1, s.size())
  {
    if (s[i] == '?')
    {
      REP(j, 13)
      {
        REP(k, 13)
        {
          dp[i][j] += dp[i - 1][(k + d[i]) % 13];
        }
      }
    }
    else
    {
      REP(k, 13)
      {
        dp[i][k] = dp[i - 1][(k + d[i]) % 13];
      }
    }
  }

  cout << dp[s.size() - 1][5].val() << endl;

  return 0;
}