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
  int n, k;
  cin >> n >> k;

  V p(n);
  REP(i, n)
  {
    cin >> p[i];
    p[i]--;
  }
  V ans(n, -1);

  if (k == 1)
  {
    REP(i, n)
    {
      ans[p[i]] = i + 1;
    }

    REP(i, n)
    {
      cout << ans[i] << endl;
    }

    return 0;
  }

  set<P> m;
  dsu d(n);

  VP so;

  REP(i, n)
  {
    if (m.size() == 0)
    {
      m.insert(make_pair(p[i], 1));
      continue;
    }

    auto it = m.upper_bound(make_pair(p[i], 0));
    if (it != m.end())
    {
      d.merge(it->first, p[i]);
      if (it->second != k - 1)
      {
        m.insert(make_pair(p[i], it->second + 1));
      }
      else
      {
        so.push_back(make_pair(d.leader(it->first), i + 1));
      }

      m.erase(it);
    }
    else
    {
      m.insert(make_pair(p[i], 1));
    }
  }

  VV gro = d.groups();

  map<int, V> gro2;
  REP(i, gro.size())
  {
    gro2[d.leader(gro[i][0])] = gro[i];
  }

  REP(k, so.size())
  {
    REP(j, gro2[so[k].first].size())
    {
      ans[gro2[so[k].first][j]] = so[k].second;
    }
  }

  REP(i, n)
  {
    cout << ans[i] << endl;
  }

  return 0;
}