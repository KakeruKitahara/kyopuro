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

  V k(m), p(m);
  VV s(m);

  REP(i, m)
  {
    cin >> k[i];
    s[i].resize(k[i]);
    REP(j, k[i])
    {
      cin >> s[i][j];
    }
  }
  REP(i, m)
  {
    cin >> p[i];
  }
  int ans = 0;

  for (int bit = 0; bit < (1 << n); bit++) // 1 << n = 2^n通り.
  {
    V ama(m);
    for (int i = 0; i < n; i++)
    {

      if (bit & (1 << i))
      {
        REP(i2, m)
        {
          REP(i3, k[i2])
          {
            if (s[i2][i3] == i + 1)
            {
              ama[i2]++;
            }
          }
        }
      }
    }
    int f = 0;
    REP(j, m)
    {
      if (ama[j] % 2 != p[j])
      {
        f = 1;
        break;
      }
    }
    if (f == 0)
    {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}