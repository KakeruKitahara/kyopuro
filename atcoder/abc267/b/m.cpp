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

/* Euclid  */
template <class X>
X gcd(X a, X b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

/* pow  */
template <class X>
X pow(X x, X n)
{
  X ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

/* fenick tree */
class fenick
{
  vector<ll> bit;
  fenick(int n)
  {
    bit.resize(n);
  }

public:
  void add(int i, ll x)
  {
    i++;
    for (int idx = i; idx <= bit.size(); idx += (idx & -idx))
    {
      bit[idx - 1] += x;
    }
  }

  ll sum(int i)
  {
    ll ans = 0;
    for (int idx = i; idx > 0; idx -= (idx & -idx))
    {
      ans += bit[idx - 1];
    }
    return ans;
  }

  ll sum(int a, int b)
  {
    return sum(b) - sum(a - 1);
  }
};

int main()
{
  S s;
  V a(10);
  cin >> s;
  REP(i, 10)
  {
    a[i] = s[i] - '0';
  }

  if (a[0] == 1)
  {
    cout << "No" << endl;
    return 0;
  }

  VV r(7);
  r[0].push_back(a[6]);
  r[1].push_back(a[3]);
  r[2].push_back(a[7]);
  r[2].push_back(a[1]);
  r[3].push_back(a[4]);
  r[3].push_back(a[0]);
  r[4].push_back(a[8]);
  r[4].push_back(a[2]);
  r[5].push_back(a[5]);
  r[6].push_back(a[9]);

  V sum(7);

  REP(i, 7)
  {
    int cnt = 0;
    REP(k, r[i].size())
    {
      if (r[i][k] == 1)
      {
        cnt++;
      }
    }
    sum[i] = cnt;
  }
  REP(i, 7)
  {
    if (sum[i] == 0)
    {
      continue;
    }

    REP2(j, i + 1, 7)
    {

      if (sum[j] == 0)
      {
        continue;
      }
      int cnt = 0;
      REP2(k, i + 1, j)
      {
        if (sum[k] == 0)
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}