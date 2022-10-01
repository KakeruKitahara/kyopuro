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
  int n;
  cin >> n;
  map<int, int> a;
  set<int> d;
  REP(i, n)
  {
    int b;
    cin >> b;
    a[b]++;
    if (a[b] >= 2)
    {
      d.insert(b);
    }
  }

  int satu = 0;
  REP2(i, 1, IINF)
  {
    if (a.size() == 0)
    {
      cout << satu << endl;
      return 0;
    }
    if (a.count(i) == false)
    {
      REP(k, 2)
      {
        if (a.size() == 0)
        {
          cout << satu << endl;
          return 0;
        }
        if (d.size() != 0)
        {
          auto it = d.begin();
          int tt = *it;
          a[tt]--;

          if (a[tt] == 1 && tt > i)
          {
            if (it == d.end())
            {
              cout << satu << endl;
              return 0;
            }
            d.erase(it);
          }

          if (a[tt] == 0)
          {
            a.erase(tt);
            d.erase(it);
          }
        }
        else
        {
          auto it2 = a.end();
          it2--;
          it2->second--;
          if (it2->second == 0)
          {
            a.erase(it2);
          }
        }
      }
    }
    else
    {
      a[i]--;
      if (a[i] >= 1)
      {
        d.insert(i);
      }
      else
      {
        a.erase(i);
      }
    }
    satu++;
  }

  return 0;
}