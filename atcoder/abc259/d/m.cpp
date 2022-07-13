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

VV ed;
V jd;
V gl;

bool dfs(int ptr)
{
  jd[ptr] = 1;
  REP(i, gl.size())
  {
    if (ptr == gl[i])
    {
      return true;
    }
  }

  bool res = false;
  REP(i, ed[ptr].size())
  {
    if (jd[ed[ptr][i]] == 0)
    {
      bool t = dfs(ed[ptr][i]);
      if (t == true)
      {
        res = true;
      }
    }
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  pair<ll, ll> s, t;
  cin >> s.first >> s.second >> t.first >> t.second;
  Vl x(n), y(n), r(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i] >> r[i];
  }

  V st;
  REP(i, n)
  {
    ll sd = (s.first - x[i]) * (s.first - x[i]) + (s.second - y[i]) * (s.second - y[i]);
    if (sd == r[i] * r[i])
    {
      st.push_back(i);
    }
  }

  REP(i, n)
  {
    ll td = (t.first - x[i]) * (t.first - x[i]) + (t.second - y[i]) * (t.second - y[i]);
    if (td == r[i] * r[i])
    {
      gl.push_back(i);
    }
  }

  ed.resize(n);

  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      ll dis = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
      if (dis <= (r[i] + r[j]) * (r[i] + r[j]) && abs(r[i] - r[j]) * abs(r[i] - r[j]) <= dis)
      {
        ed[i].push_back(j);
        ed[j].push_back(i);
      }
    }
  }

  jd.resize(n);

  REP(i, st.size())
  {
    if (dfs(st[i]) == true)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}