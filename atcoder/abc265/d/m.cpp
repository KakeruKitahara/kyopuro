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
  ll n, p, q, r;
  cin >> n >> p >> q >> r;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  Vl sum(n + 1);
  sum[0] = 0;
  REP(i, n)
  {
    sum[i + 1] = a[i] + sum[i];
  }

  int j = 0;

  V pp;
  V qq;
  V rr;
  REP2(i, 1, n + 1)
  {
    while (i >= j && sum[i] - sum[j] > p)
    {
      j++;
    }
    if (sum[i] - sum[j] == p)
    {
      pp.push_back(j);
    }
  }

  j = 0;
  REP2(i, 1, n + 1)
  {
    while (sum[i] - sum[j] > p + q && i >= j)
    {
      j++;
    }
    if (sum[i] - sum[j] == q + p)
    {
      qq.push_back(j);
    }
  }

  j = 0;
  REP2(i, 1, n + 1)
  {
    while (sum[i] - sum[j] > p + q + r && i >= j)
    {
      j++;
    }
    if (sum[i] - sum[j] == r + p + q)
    {
      rr.push_back(j);
    }
  }

  sort(pp.begin(), pp.end());
  sort(qq.begin(), qq.end());
  sort(rr.begin(), rr.end());

  REP(i, pp.size())
  {
    auto it = lower_bound(qq.begin(), qq.end(), pp[i]);
    if (it != qq.end() && pp[i] == *it)
    {
      auto it2 = lower_bound(rr.begin(), rr.end(), *it);
      if (it2 != rr.end() && *it == *it2)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}