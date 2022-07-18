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
int a, b;
V aa, bb;

bool fx(int m)
{
  ll mi = 0;
  ll pu = 0;
  REP(i, aa.size())
  {

    int t = aa[i] - m;
    if (t > 0)
    {
      pu += t / b;
    }
    else
    {
      mi += (-t + a - 1) / a;
    }
  }

  if (pu < mi)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int n;
  cin >> n >> a >> b;

  aa.resize(n);
  bb.resize(n);
  REP(i, n)
  {
    cin >> aa[i];
  }
  int ans;

  /* left + 1 ~ right - 1を探索するが，
  これが偶数のみやsの倍数のみなど，数値が飛んでいる数直線上でおこなうとき，
  if文のmidをmid * s としてansの代入数値をright * sとする．このとき捜索範囲が1/sとなる．*/
  
  ll left = 0, right = IINF;
  
  while (right - left > 1)
  {
    ll mid = left + (right - left) / 2;
    if (fx(mid)) // f(mid)の値とkeyを比較してkey以上だったらac
      right = mid; // ac
    else
      left = mid; // wa
  }
  ans = right; // ansがacを満たす最小値となる．

  return 0;
}