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

V bit;

void up(int i, ll x)
{
  i++;
  while (i <= bit.size())
  {
    bit[i - 1] = bit[i - 1] ^ x;
    i += (i & -i);
  }
}

ll sum(int i)
{
  ll ans = 0;
  while (i > 0)
  {
    ans = bit[i - 1] ^ ans;
    i -= (i & -i);
  }
  return ans;
}

int main()
{
  int n, q;
  cin >> n >> q;

  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  bit.resize(n);
  Vl t(q), x(q), y(q);

  REP(i, q)
  {
    cin >> t[i] >> x[i] >> y[i];
  }

  REP(i, n)
  {
    up(i, a[i]);
  }

  REP(i, q)
  {
    if (t[i] == 1)
    {
      x[i]--;
      up(x[i], y[i]);
    }
    else
    {
      y[i]--;
      x[i]--;

      ll a2 = sum(y[i]);
      ll b2 = sum(max(0ll, x[i] - 1));
      a2 ^= b2;
      cout << a2 << endl;
    }
  }

  return 0;
}