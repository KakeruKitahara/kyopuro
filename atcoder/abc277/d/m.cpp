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
template <typename T>
class Fenick
{
  vector<T> bit;

public:
  Fenick(int n)
  {
    bit.resize(n);
  }

  void add(int i, T x)
  {
    for (int idx = i + 1; idx <= bit.size(); idx += idx & (-idx))
    {
      bit[idx - 1] += x;
    }
  }

  T sum(int i)
  {
    T ans = 0;
    for (int idx = i + 1; idx > 0; idx -= idx & (-idx))
    {
      ans += bit[idx - 1];
    }
    return ans;
  }

  T sum(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  map<ll, ll> mp;
  ll sum = 0;
  REP(i, n)
  {
    int a;
    cin >> a;
    sum += a;

    mp[a]++;
  }

  ll ans = -1;
  if (mp.count(0) == 0)
  {
    int pre = -1;
    ll tmp = 0;

    for (auto k : mp)
    {

      if ((pre + 1) % m == k.first || pre == -1)
      {
        tmp += k.first * k.second;
      }
      else
      {
        ans = max(tmp, ans);
        tmp = 0;
        tmp += k.first * k.second;
      }

      pre = k.first;
    }

    ans = max(tmp, ans);
  }
  else
  {

    int pre = -1;
    ll tmp = 0;
    int f = 0;
    auto d = mp.begin();
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
      if (pre + 1 != it->first)
      {
        f = 1;
        d = it;
        break;
      }

      pre = it->first;
    }

    if (f == 0)
    {
      cout << 0 << endl;
      return 0;
    }
    int cnt = 0;
    for (auto it = d;; it++)
    {
      if (it == d)
      {

        if (cnt == 1)
        {
          ans = max(tmp, ans);
          break;
        }
        cnt++;
      }

      if (it == mp.end())
      {
        it = mp.begin();
      }

      if ((pre + 1) % m == it->first || pre == -1)
      {
        tmp += it->first * it->second;
      }
      else
      {
        ans = max(tmp, ans);
        tmp = 0;
        tmp += it->first * it->second;
      }

      pre = it->first;
    }
  }

  cout << sum - ans << endl;

  return 0;
}