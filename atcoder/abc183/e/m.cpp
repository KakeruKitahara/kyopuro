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
  vector<S> s;
  int h, w;
  cin >> h >> w;
  s.resize(h);

  for (int i = 0; i < h; i++)
  {
    cin >> s[i];
  }

  VVV dp(h, VV(w, V(3)));
  P w2[3] = {make_pair(-1, 0), make_pair(0, -1), make_pair(-1, -1)};
  REP(i, h)
  {
    REP(j, w)
    {
      P ptr = make_pair(i, j);
      if (s[ptr.first][ptr.second] == '.')
      {
        REP(l, 3)
        {
          P pre = ptr + w2[l];
          int k = 1;
          if (0 <= pre.first && pre.first < h && 0 <= pre.second && pre.second < w && s[pre.first][pre.second] == '.')
          {
            P ppre = pre + w2[l];
            if (0 <= ppre.first && ppre.first < h && 0 <= ppre.second && ppre.second < w && s[ppre.first][ppre.second] == '.')
            {
              k = 2;
            }
            if (dp[pre.first][pre.second][l] == 0)
            {
              dp[ptr.first][ptr.second][l] = 1;
            }
            else
            {
              dp[ptr.first][ptr.second][l] += dp[pre.first][pre.second][l] * k;
            }
          }
        }
      }
    }
  }

  int ans = 0;


  return 0;
}