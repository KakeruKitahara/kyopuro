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
  S s;
  cin >> s;
  int q;
  cin >> q;
  dsu d(n + q + 10);
  int ind = n;
  int oo = -1, kk = -1;
  V sind(n);
  REP(i, n)
  {
    sind[i] = i;
    if (isupper(s[i]))
    {
      if (oo != -1)
      {
        d.merge(oo, i);
      }
      oo = i;
    }
    else
    {
      if (kk != -1)
      {
        d.merge(kk, i);
      }
      kk = i;
    }
  }

  if (oo != -1)
  {
    oo = d.leader(oo);
  }
  if (kk != -1)
  {
    kk = d.leader(kk);
  }
  REP(i, q)
  {
    int t, x;
    char c;
    cin >> t >> x >> c;
    x--;
    if (t == 1)
    {
      sind[x] = ind;
      s[x] = c;
      if (isupper(c))
      {
        if (oo != -1)
        {
          d.merge(oo, ind);
          oo = d.leader(oo);
        }
        else
        {
          oo = ind;
        }
      }
      else
      {
        if (kk != -1)
        {
          d.merge(kk, ind);
          kk = d.leader(kk);
        }
        else
        {
          kk = ind;
        }
      }
      ind++;
    }
    else if (t == 3)
    {
      if (kk == -1)
      {
        continue;
      }
      if (oo == -1)
      {
        oo = d.leader(kk);
        kk = -1;
        continue;
      }
      d.merge(kk, oo);
      kk = -1;

      oo = d.leader(oo);
    }
    else
    {
      if (oo == -1)
      {
        continue;
      }
      if (kk == -1)
      {
        kk = d.leader(oo);
        oo = -1;
        continue;
      }
      d.merge(kk, oo);
      oo = -1;
      kk = d.leader(kk);
    }
  }

  VV g = d.groups();
  set<int> og, kg;
  int f = 0;
  REP(i, g.size())
  {
    REP(j, g[i].size())
    {
      if (oo == g[i][j])
      {
        REP(l, g[i].size())
        {
          og.insert(g[i][l]);
        }
        f = 1;
        break;
      }
    }
    if (f == 1)
    {
      break;
    }
  }
  f = 0;

  REP(i, g.size())
  {
    REP(j, g[i].size())
    {
      if (kk == g[i][j])
      {
        REP(l, g[i].size())
        {
          kg.insert(g[i][l]);
        }
        f = 1;
        break;
      }
    }
    if (f == 1)
    {
      break;
    }
  }

  REP(i, n)
  {
    if (og.count(sind[i]) && islower(s[i]))
    {
      cout << (char)toupper(s[i]);
    }
    else if (kg.count(sind[i]) && isupper(s[i]))
    {

      cout << (char)tolower(s[i]);
    }
    else
    {
      cout << s[i];
    }
  }

  cout << endl;

  return 0;
}