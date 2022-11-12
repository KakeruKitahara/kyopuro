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
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  Vl s2;
  Vl s3;

  ll t2 = 2;
  while (t2 < IINF)
  {
    s2.push_back(t2);
    t2 *= 2;
  }

  ll t3 = 3;
  while (t3 < IINF)
  {
    s3.push_back(t3);
    t3 *= 3;
  }
  VV cnt(n);
  REP(i, n)
  {
    int tans = 0;

    cnt[i].resize(2);
    REPR(k, s2.size())
    {
      if (a[i] % s2[k] == 0)
      {
        cnt[i][0] = k + 1;
        a[i] /= s2[k];
      }
    }

    REPR(k, s3.size())
    {
      if (a[i] % s3[k] == 0)
      {
        cnt[i][1] = k + 1;
        a[i] /= s3[k];
      }
    }
  }

  REP(i, n - 1)
  {
    if (a[i] != a[i + 1])
    {
      cout << -1 << endl;
      return 0;
    }
  }
  int tt2 = 100;
  int tt3 = 100;
  REP(i, n)
  {
    tt2 = min(tt2, cnt[i][0]);
  }

  REP(i, n)
  {
    tt3 = min(tt3, cnt[i][1]);
  }
  ll ans = 0;
  REP(i, n)
  {
    ans += cnt[i][0] - tt2;
    ans += cnt[i][1] - tt3;
  }

  cout << ans << endl;
  return 0;
}