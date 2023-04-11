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
  V a(n);
  VVP xy(n);

  REP(i, n)
  {
    cin >> a[i];
    xy[i].resize(a[i]);
    REP(j, a[i])
    {
      cin >> xy[i][j].first >> xy[i][j].second;
    }
  }

  int ans = 0;

  for (ll bit = 0; bit < (1 << n); bit++)
  {
    int f = 0;
    int cnt = 0;
    VVP gen = xy;
    for (int i = 0; i < n; i++)
    {

      if (bit & (1 << i))
      {
        cnt++;
        REP(j, a[i])
        {
          if ((bit & (1 << (gen[i][j].first - 1))) != (gen[i][j].second * (1 << (gen[i][j].first - 1))))
          {
            f = 1;
          }
        }
      }
    }

    if (f == 0)
    {
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;

  return 0;
}
