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
  int h, w;
  cin >> h >> w;
  vector<S> g(h);
  REP(i, h)
  {
    cin >> g[i];
  }

  VV jd(h, V(w));

  P p = make_pair(0, 0);
  while (1)
  {
    if (p.first < 0)
    {
      cout << p.first + 2 << " " << p.second + 1 << endl;
      return 0;
    }
    else if (h <= p.first)
    {
      cout << p.first << " " << p.second + 1 << endl;
      return 0;
    }
    else if (p.second < 0)
    {
      cout << p.first + 1 << " " << p.second + 2 << endl;
      return 0;
    }
    else if (w <= p.second)
    {
      cout << p.first + 1 << " " << p.second << endl;
      return 0;
    }
    if (jd[p.first][p.second] == 1)
    {
      cout << -1 << endl;
      return 0;
    }
    char a = g[p.first][p.second];
    jd[p.first][p.second] = 1;
    if (a == 'U')
    {
      p.first--;
    }
    else if (a == 'D')
    {
      p.first++;
    }
    else if (a == 'L')
    {
      p.second--;
    }
    else if (a == 'R')
    {
      p.second++;
    }
  }

  return 0;
}