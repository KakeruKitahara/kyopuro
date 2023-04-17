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

  vector<mint> ans(k + 1);
  mint c = 1;
  mint b = 1;
  mint a = 1;

  mint x = 2;
  mint y = min(n - k, 2);
  mint z = max(2 - min(n - k, 2), 1);

  REP2(i, 1, k)
  {
    c *= i;
    b *= i;
  }
  int t = min(k, n - k + 1);

  REP2(i, 1, t + 1)
  {
    mint rkci = x / (y * z);
    int t1 = i - 1 + 2;
    int t2 = n - k - (i - 1);
    mint rtmps = 0;
    rtmps += rkci;
    mint rkci2 = rkci;
    REP2(j, 1, t2)
    {
      rkci2 *= (i + j);
      rtmps += rkci2;
    }
    mint bkci = c / (a * b);
    mint an = bkci * rtmps;
    ans[i] = an;
    if (i == t)
    {
      break;
    }
    b /= (k - i);
    a *= i;
    x *= (t1 + 1);
    y *= t2;
    z *= t1 - t2 + 1;
  }

  REP2(i, 1, k + 1)
  {
    cout << ans[i].val() << endl;
  }
  return 0;
}