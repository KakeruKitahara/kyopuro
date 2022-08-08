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

  Vl sumx(n), sumy(n);
  ll bx = l, by = r;
  sumx[0] = a[0];
  REP2(i, 1, n)
  {
    sumx[i] = sumx[i - 1] + a[i];
  }

  ll x = -1, y = -1;
  Vl minsumx(n, sumx[n - 1]);

  REP(i, n)
  {

    if (i == 0)
    {
      if (sumx[n - 1] - sumx[i] + bx < minsumx[0])
      {
        minsumx[i] = sumx[n - 1] - sumx[i] + bx;
        x = i;
      }
      continue;
    }
    if (sumx[n - 1] - sumx[i] + bx < minsumx[i - 1])
    {
      minsumx[i] = sumx[n - 1] - sumx[i] + bx;
      x = i;
    }
    else
    {
      minsumx[i] = minsumx[i - 1];
    }

    bx += l;
  }
  reverse(a.begin(), a.end());
  x = n - x - 1;
  if (x == 0)
  {
    sumy[0] = l;
  }
  else
  {
    sumy[0] = a[0];
  }

  REP2(i, 1, n)
  {
    if (i >= x)
    {
      sumy[i] = sumy[i - 1] + l;
    }
    else
    {
      sumy[i] = sumy[i - 1] + a[i];
    }
  }

  Vl minsumy(n, sumy[n - 1]);

  REP(i, n)
  {
    if (i == 0)
    {
      if (sumy[n - 1] - sumy[i] + by < minsumy[0])
      {
        minsumy[i] = sumy[n - 1] - sumy[i] + by;
        y = i;
      }
      continue;
    }
    if (sumy[n - 1] - sumy[i] + by < minsumy[i - 1])
    {
      minsumy[i] = sumy[n - 1] - sumy[i] + by;
      y = i;
    }
    else
    {
      minsumy[i] = minsumy[i - 1];
    }

    by += r;
  }
  ll ans = 0;
  REP(i, n)
  {
    if (i <= y)
    {
      ans += r;
    }
    else if (x <= i)
    {
      ans += l;
    }
    else
    {
      ans += a[i];
    }
  }
  cout << ans << endl;
  return 0;
}

/*
3
1 5 
0 0 10
-------
3
になるので，xとyのときでともに最小になるxとyを選出する解放は無理．
逐次的におこなってminと比較するしかない．
*/