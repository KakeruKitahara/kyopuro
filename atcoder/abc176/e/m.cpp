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
  int h, w, m;
  cin >> h >> w >> m;
  VP wr(w), hr(h);
  map<P, int> mp;
  REP(i, m)
  {
    int h2, w2;
    cin >> h2 >> w2;
    wr[w2 - 1].first++;
    hr[h2 - 1].first++;
    mp[make_pair(h2 - 1, w2 - 1)] = 1;
  }

  REP(i, h)
  {
    hr[i].second = i;
  }

  REP(i, w)
  {
    wr[i].second = i;
  }

  sort(wr.rbegin(), wr.rend());
  sort(hr.rbegin(), hr.rend());


  int hk, wk;
  REP(i, w)
  {
    if (wr[i].first != wr[i + 1].first)
    {
      wk = i;
      break;
    }
  }

  REP(i, h)
  {
    if (hr[i].first != hr[i + 1].first)
    {
      hk = i;
      break;
    }
  }

  REP(i, hk + 1)
  {
    REP(j, wk + 1)
    {
      if (mp[make_pair(hr[i].second, wr[j].second)] == 0)
      {
        cout << hr[i].first + wr[j].first << endl;
        return 0;
      }
    }
  }
  cout << hr[0].first + wr[0].first - 1 << endl;
  return 0;
}