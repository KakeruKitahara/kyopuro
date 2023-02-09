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
  ll n, l, r;
  cin >> n >> l >> r;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  Vl x(n), y(n);
  REP(i, n)
  {
    x[i] = l * (i + 1);
    y[i] = r * (i + 1);
  }

  Vl suml(n + 1);
  REP2(i, 1, n + 1)
  {
    suml[i] = min(x[i - 1], suml[i - 1] + a[i - 1]);
  }

  reverse(a.begin(), a.end());

  Vl sumr(n + 1);
  REP2(i, 1, n + 1)
  {
    sumr[i] = min(sumr[i - 1] + a[i - 1], y[i - 1]);
  }

  reverse(sumr.begin(), sumr.end());

  ll ans = LINF;
  REP(i, n + 1)
  {
    ans = min(ans, suml[i] + sumr[i]);
  }

  cout << ans << endl;

  return 0;
}
