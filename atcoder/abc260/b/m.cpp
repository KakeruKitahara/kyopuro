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

  int n, x, y, z;
  cin >> n >> x >> y >> z;

  VP a(n), b(n), c(n);
  REP(i, n)
  {
    cin >> a[i].first;
    a[i].second = -i;
  }

  REP(i, n)
  {
    cin >> b[i].first;
    b[i].second = -i;
  }

  REP(i, n)
  {
    c[i].first = a[i].first + b[i].first;
    c[i].second = -i;
  }

  sort(a.rbegin(), a.rend());

  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());

  int cnt = 0;

  V o(n);
  while (cnt != x)
  {
    REP(i, n)
    {
      if (o[-a[i].second] == 0)
      {
        o[-a[i].second] = 1;
        cnt++;
        break;
      }
    }
  }
  cnt = 0;
  while (cnt != y)
  {
    REP(i, n)
    {
      if (o[-b[i].second] == 0)
      {
        o[-b[i].second] = 1;
        cnt++;
        break;
      }
    }
  }

  cnt = 0;
  while (cnt != z)
  {
    REP(i, n)
    {
      if (o[-c[i].second] == 0)
      {
        o[-c[i].second] = 1;
        cnt++;
        break;
      }
    }
  }

  REP(i, n)
  {
    if (o[i] == 1)
    {
      cout << i + 1 << endl;
    }
  }

  return 0;
}