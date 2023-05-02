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

template <typename T>
vector<pair<T, T>> prime_factor(T n)
{
  vector<pair<T, T>> ret;
  for (T i = 2; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    T tmp = 0;
    while (n % i == 0)
    {
      tmp++;
      n /= i;
    }
    ret.push_back(make_pair(i, tmp));
  }
  if (n != 1)
    ret.push_back(make_pair(n, 1));
  return ret;
}

int main()
{
  int n;
  cin >> n;

  map<int, int> so;

  REP2(i, 2, n + 1)
  {
    VP tmp = prime_factor(i);
    REP(j, tmp.size())
    {
      so[tmp[j].first] += tmp[j].second;
    }
  }

  int s5 = 0, s3 = 0, s15 = 0, s25 = 0, s75 = 0;
  for (auto p : so)
  {
    if (p.second >= 74)
    {
      s75++;
    }
    else if (p.second >= 24)
    {
      s25++;
    }
    else if (p.second >= 14)
    {
      s15++;
    }
    if (p.second >= 4)
    {
      s5++;
    }
    else if (p.second >= 2)
    {
      s3++;
    }
  }

  int ans = 0;
  ans += s75;

  ans += (s75 + s25) * (s3 + s5 + s15);
  ans += s75 * s25;
  ans += s75 * (s75 - 1);
  ans += s25 * (s25 - 1);

  ans += (s75 + s25 + s15) * s5;
  ans += s75 * s25;
  ans += s75 * s15;
  ans += s25 * s15;
  ans += s75 * (s75 - 1);
  ans += s25 * (s25 - 1);
  ans += s15 * (s15 - 1);

  s5 += s15 + s25 + s75;

  int m = (s3 * (s3 - 1)) / 2 * s5;
  m += s3 * (s3 - 1) * (s3 - 2) / 6;

  s5 += s3;

  ans += s5 * (s5 - 1) * (s5 - 2) / 6;

  cout << ans - m << endl;
  return 0;
}