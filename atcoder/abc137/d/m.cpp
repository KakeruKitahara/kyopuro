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

  multiset<P> maxs;
  vector<multiset<int>> q(m + 1);
  V box(m + 1);
  REP(i, n)
  {
    int a, b;
    cin >> a >> b;
    if (a <= m)
      q[a].insert(b);
  }

  REP2(i, 1, m + 1)
  {
    if (q[i].size() == 0)
      continue;
    auto tp = q[i].end();
    tp--;
    maxs.insert({*tp, i});
    box[i] = *tp;
    q[i].erase(tp);
  }

  ll ans = 0;
  REP(i, m)
  {
    if (maxs.size() == 0)
      break;
    auto tp = maxs.end();
    tp--;
    ans += tp->first;
    int ind = tp->second;

    if (tp->first == box[m - i] && tp->second == m - i)
    {
      maxs.erase(tp);
    }
    else
    {
      maxs.erase(tp);
      maxs.erase({box[m - i], m - i});
    }

    if (q[ind].size() != 0)
    {
      if (i + ind + 1 <= m)
      {
        auto pp = q[ind].end();
        pp--;
        maxs.insert({*pp, ind});
        box[ind] = *pp;
        q[ind].erase(pp);
      }
    }
  
  }

  cout << ans << endl;
  return 0;
}