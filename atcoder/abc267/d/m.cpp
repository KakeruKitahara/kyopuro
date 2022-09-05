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

int main()
{
  ll n, m;
  cin >> n >> m;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  VVl dp(n, Vl(m, -LINF));
  Vl maxdp(m, -LINF);
  REP(i, n)
  {
    ll k = i + 1;
    ll tmp = -LINF;
    REP(j, min(k, m))
    {
      if (j == 0)
      {
        dp[i][j] = a[i];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], maxdp[j - 1] + a[i] * (j + 1));
        maxdp[j - 1] = tmp;
      }

      tmp = max(maxdp[j], dp[i][j]);
    }
    maxdp[min(k, m) - 1] = tmp;
  }

  cout << dp[n - 1][m - 1] << endl;
  return 0;
}