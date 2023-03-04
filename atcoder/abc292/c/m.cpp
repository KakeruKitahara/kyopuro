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

vector<pair<long long, long long>> prime_factorize(long long N)
{

  vector<pair<long long, long long>> res;

  for (long long p = 2; p * p <= N; ++p)
  {

    if (N % p != 0)
    {
      continue;
    }

    int e = 0;
    while (N % p == 0)
    {

      ++e;

      N /= p;
    }

    res.emplace_back(p, e);
  }

  if (N != 1)
  {
    res.emplace_back(N, 1);
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  int a = 1, b = n - 1;
  ll ans = 0;
  while (a != n)
  {
    vector<pair<long long, long long>> aa = prime_factorize(a);

    vector<pair<long long, long long>> bb = prime_factorize(b);

    ll tmpa = 1, tmpb = 1;
    REP(i, aa.size())
    {
      tmpa *= (aa[i].second + 1);
    }
    REP(i, bb.size())
    {

      tmpb *= (bb[i].second + 1);
    }

    ans += tmpa * tmpb;
    a++;
    b--;
  }

  cout << ans << endl;
  return 0;
}