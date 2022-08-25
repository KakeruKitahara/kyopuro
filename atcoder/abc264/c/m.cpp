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
  int h1, h2, w1, w2;
  cin >> h1 >> w1;
  VV a(h1, V(w1));
  REP(i, h1)
  {
    REP(j, w1)
    {
      cin >> a[i][j];
    }
  }
  cin >> h2 >> w2;
  VV b(h2, V(w2));
  REP(i, h2)
  {
    REP(j, w2)
    {
      cin >> b[i][j];
    }
  }

  map<int, V> v;

  REP(i, h1)
  {
    int k = 0;
    V t;
    REP(j, w1)
    {
      if (a[i][j] == b[0][k])
      {
        t.push_back(j);
        k++;
      }
      if (k == w2)
      {
        break;
      }
    }
    if (k == w2)
    {
      v[i] = t;
    }
  }

  if (h2 == 1)
  {
    if (v.size() == 0)
    {
      cout << "No" << endl;
      return 0;
    }
    else
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  for (auto p : v)
  {
    V t2 = p.second;
    int s = p.first;
    int bi = 1;

    REP2(i, s, h1)
    {
      int f = 0;
      REP(j, t2.size())
      {
        if (a[i][t2[j]] == b[bi][j])
        {
          f++;
        }
      }
      if (f == t2.size())
      {
        bi++;
        if (bi == h2)
        {
          break;
        }
      }
    }

    if (bi == h2)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
