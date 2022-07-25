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
  int n, m, k;
  cin >> n >> m >> k;

  VP a, b;

  REP(i, n)
  {
    int aa;
    cin >> aa;
    if (a.size() == 0 || a.back().first != aa)
    {
      a.push_back(make_pair(aa, 1));
    }
    else
    {
      a.back().second++;
    }
  }

  REP(i, m)
  {
    int bb;
    cin >> bb;
    if (b.size() == 0 || b.back().first != bb)
    {
      b.push_back(make_pair(bb, 1));
    }
    else
    {
      b.back().second++;
    }
  }

  ll g = 0;
  int i = 0, j = 0;
  while (1)
  {
    if (a[i].first == b[j].first)
    {
      if (i + 1 != a.size() - 1 && j + 1 != b.size() - 1)
      {
        if(a[i + 1].first < b[j + 1].first){
          
        }
      }
    }
  }

  return 0;
}