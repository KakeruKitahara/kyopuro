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
  int n;
  cin >> n;
  V a(n + 1);
  REP2(i, 1, n + 1)
  {
    cin >> a[i];
  }
  mint ans = 0;

  REP2(l, 1, n + 1)
  {
    vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(n + 1, vector<mint>(n)));
    dp[0][0][0] = 1;
    REP2(i, 1, n + 1)
    {
      REP(j, i + 1)
      {
        if (j == 0)
        {
          dp[i][j][0] = dp[i - 1][j][0];
          continue;
        }
        REP(k, n)
        {
          ll indk = k - a[i];
          indk += l * (ll)IINF;
          indk %= l;

          dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][indk];
        }
      }
    }

    ans += dp[n][l][0];
  }

  cout << ans.val() << endl;

  return 0;
}