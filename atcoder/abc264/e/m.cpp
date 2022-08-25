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
  int n, m, e;
  cin >> n >> m >> e;
  V u(e), v(e);
  REP(i, e)
  {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }

  int q;
  cin >> q;
  map<int, int> sh;
  V x(q);
  REP(i, q)
  {
    cin >> x[i];
    x[i]--;
    sh[x[i]] = 1;
  }

  dsu d(n + m);

  REP(i, e)
  {
    if (sh.count(i) == 1)
      continue;

    if (d.same(u[i], v[i]) == false)
    {
      d.merge(u[i], v[i]);
    }
  }

  ll cnt = 0;

  map<int, int> cl;
  REP2(i, n, n + m)
  {
    if (cl.count(d.leader(i)) == 0)
    {
      cnt += d.size(i);
      cl[d.leader(i)] = 1;
    }
  }

  cnt -= m;

  V ans;


  REPR(i, q)
  {
    ans.push_back(cnt);
    if (d.same(u[x[i]], v[x[i]]) == false)
    {
      if (cl.count(d.leader(u[x[i]])) == 0 && cl.count(d.leader(v[x[i]])) == 0)
      {
        d.merge(u[x[i]], v[x[i]]);
      }
      else if (cl.count(d.leader(u[x[i]])) == 0 && cl.count(d.leader(v[x[i]])) == 1)
      {
        cl.erase(d.leader(u[x[i]]));
        cl.erase(d.leader(v[x[i]]));
        cnt += d.size(u[x[i]]);
        d.merge(u[x[i]], v[x[i]]);
        cl[d.leader(u[x[i]])] = 1;
      }
      else if (cl.count(d.leader(u[x[i]])) == 1 && cl.count(d.leader(v[x[i]])) == 0)
      {
        cl.erase(d.leader(u[x[i]]));
        cl.erase(d.leader(v[x[i]]));
        cnt += d.size(v[x[i]]);
        d.merge(u[x[i]], v[x[i]]);
        cl[d.leader(u[x[i]])] = 1;
      }
      else if (cl.count(d.leader(u[x[i]])) == 1 && cl.count(d.leader(v[x[i]])) == 1)
      {
        cl.erase(d.leader(u[x[i]]));
        cl.erase(d.leader(v[x[i]]));
        d.merge(u[x[i]], v[x[i]]);
        cl[d.leader(u[x[i]])] = 1;
      }
    }
  }

  REPR(i, ans.size())
  {
    cout << ans[i] << endl;
  }

  return 0;
}