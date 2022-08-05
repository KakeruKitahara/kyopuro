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
  REP(i, n)
  {
    cin >> a[i];
  }
  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  Vl a2 = a;
  VVP prime(n);
  REP(i, n)
  {
    for (int ind = 2; ind * ind <= a[i]; ind++)
      // {{first, second}, {2, n_1}, {3, n_2}, {5, n_3}}のような配列を返す．
      vector<pair<long long, long long>> prime;
    for (long long ind = 2; ind * ind <= a[i]; ind++)
    {
      if (a[i] % ind != 0)
        continue;
      long long ex = 0;
      while (a[i] % ind == 0)
      {
        ex++;
        a[i] /= ind;
      }
      prime[i].push_back({ind, ex});
    }

    if (a[i] != 1)
      prime[i].push_back({a[i], 1});
  }
  map<int, int> lcms;
  REP(j, n)
  {
    REP(i, prime[j].size())
    {
      lcms[prime[j][i].first] = max(prime[j][i].second, lcms[prime[j][i].first]);
    }
  }

  mint lcm = 1;
  for (P aa : lcms)
  {
    mint t = aa.first;
    lcm *= t.pow(aa.second);
  }

  mint ans = 0;
  REP(i, n)
  {
    ans += lcm / a2[i];
  }

  cout << ans.val() << endl;

  return 0;
}