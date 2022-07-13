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
  V p(n), q(n);
  REP(i, n)
  {
    cin >> p[i];
  }
  REP(i, n)
  {
    cin >> q[i];
  }
  V a(n);
  REP(i, n)
  {
    a[i] = i + 1;
  }
  V a22 = a;
  int aa = 0;

  int a1;
  do
  {
    int cnt = 0;
    aa++;
    REP(i, n)
    {
      if (a[i] == p[i])
        cnt++;
    }
    if (cnt == n)
    {
      a1 = aa;
      break;
    }
  } while (next_permutation(a.begin(), a.end()));
  aa = 0;
  int b1;
  do
  {
    int cnt = 0;
    aa++;
    REP(i, n)
    {
      if (a22[i] == q[i])
        cnt++;
    }
    if (cnt == n)
    {
      b1 = aa;
      break;
    }
  } while (next_permutation(a22.begin(), a22.end()));

  cout << abs(a1 - b1) << endl;

  return 0;
}