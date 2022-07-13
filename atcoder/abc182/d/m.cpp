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
  Vl a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  if(n == 1){
    cout << max(a[0], 0ll) << endl;
    return 0;
  }

  Vl sum(n);
  sum[0] = a[0];

  REP2(i, 1, n)
  {
    sum[i] = a[i] + sum[i - 1];
  }

  Vl za(n - 1);

  za[0] = sum[0];
  REP2(i, 1, n - 1)
  {
    za[i] = sum[i] + za[i - 1];
  }
  ll maxs = -1;
  int ind = -1;
  REP(i, n - 1)
  {
    if (maxs <= za[i])
    {
      maxs = za[i];
      ind = i;
    }
  }
  ll maxs2 = -1;
  int ind2 = -1;

  if (ind == -1)
  {
    cout << 0 << endl;
    return 0;
  }

  REP(i, ind + 2)
  {
    if (maxs2 < sum[i])
    {
      maxs2 = sum[i];
      ind2 = i;
    }
  }

  if (ind2 == -1)
  {
    maxs2 = 0;
  }

  cout << maxs2 + maxs << endl;

  return 0;
}