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
using mint = modint998244353;

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

  int c = 0;
  int n = s.size();
  vector<vector<mint>> dp(n, vector<mint>(n + 10));
  if (s[0] == ')')
  {
    cout << 0 << endl;
    return 0;
  }

  dp[0][1] = 1;
  REP2(i, 1, n)
  {
    REP(j, n + 7)
    {
      if (s[i] == '(')
      {
        if (j == 0)
        {
          dp[i][j] = 0;
        }
        else
        {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
      else if (s[i] == ')')
      {
        dp[i][j] = dp[i - 1][j + 1];
      }
      else
      {
        if (j == 0)
        {
          dp[i][j] = dp[i - 1][j + 1];
        }
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
      }
    }
  }

  cout << dp[n - 1][0].val() << endl;
  return 0;
}