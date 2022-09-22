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
  int a = 1, c = 1, preh = n, h = n / 2, prew = n, w = n;
  int ansx, ansy;
  int f = 0;
  REP(i, 20)
  {

    cout << "? " << a << " " << a + h - 1 << " " << c << " " << c + w - 1 << endl;

    int t;
    cin >> t;

    if (f == 0)
    {
      if (h == t)
      {
        a = a + h;
        h = (preh - a + 1) / 2;
      }
      else
      {
        preh = a + h - 1;
        h /= 2;
      }

      if (h == 0)
      {
        ansy = a;
        w /= 2;
        f = 1;
        a = 1;
        h = n;
      }
    }
    else
    {
      if (w == t)
      {
        c = c + w;
        w = (prew - c + 1) / 2;
      }
      else
      {
        prew = w + c - 1;
        w /= 2;
      }
      if (w == 0)
      {
        ansx = c;
      }
    }

    if (w == 0)
    {
      cout << "! " << ansy << " " << ansx << endl;
      return 0;
    }
  }

  return 0;
}