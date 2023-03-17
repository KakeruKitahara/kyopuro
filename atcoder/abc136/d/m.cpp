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
  S s;
  cin >> s;
  V r, l;
  V ans(s.size());
  REP(i, s.size())
  {
    if (s[i] == 'R')
    {
      r.push_back(-i);
    }
    else
    {
      l.push_back(i);
    }
  }

  sort(r.begin(), r.end());
  sort(l.begin(), l.end());

  REP(i, s.size())
  {
    if (s[i] == 'R')
    {
      auto p = lower_bound(l.begin(), l.end(), i);
      if ((*p - i) % 2 == 1)
      {
        ans[*p - 1]++;
      }
      else
      {
        ans[*p]++;
      }
    }
    else
    {
      auto p = lower_bound(r.begin(), r.end(), -i);
      if ((-*p + i) % 2 == 1)
      {
        ans[-*p + 1]++;
      }
      else
      {
        ans[-*p]++;
      }
    }
  }

  REP(i, s.size())
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}