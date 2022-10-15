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
  ll h, w, c1, r1;
  cin >> h >> w >> r1 >> c1;
  r1--;
  c1--;
  ll n;
  cin >> n;

  map<ll, set<ll>> xs;
  map<ll, set<ll>> ys;

  REP(i, n)
  {
    ll r, c;
    cin >> r >> c;
    xs[r - 1].insert(c - 1);
    ys[c - 1].insert(r - 1);
  }

  for (auto &i : xs)
  {
    i.second.insert(-1);
    i.second.insert(w);
  }

  for (auto &i : ys)
  {
    i.second.insert(-1);
    i.second.insert(h);
  }

  int q;
  cin >> q;

  vector<char> d(q);
  Vl l(q);

  REP(i, q)
  {
    cin >> d[i] >> l[i];
  }

  REP(i, q)
  {
    ll ta;
    if (d[i] == 'L')
    {
      ta = c1 - l[i];

      if (xs.count(r1) == 0)
      {
        c1 = max(ta, 0ll);
        cout << r1 + 1 << " " << c1 + 1 << endl;
        continue;
      }

      int f = -2;
      if (xs[r1].count(c1) == 0)
      {
        f = c1;
        xs[r1].insert(c1);
      }
      auto p = xs[r1].find(c1);
      p--;

      if (ta <= *p)
      {
        c1 = *p + 1;
      }
      else
      {
        c1 = ta;
      }

      if (f != -2)
      {
        xs[r1].erase(f);
      }
    }
    else if (d[i] == 'R')
    {
      ta = c1;

      if (xs.count(r1) == 0)
      {
        c1 = min(c1 + l[i], w - 1);
        cout << r1 + 1 << " " << c1 + 1 << endl;
        continue;
      }

      auto p = xs[r1].lower_bound(ta);

      if (*p <= c1 + l[i])
      {
        c1 = *p - 1;
      }
      else
      {
        c1 = c1 + l[i];
      }
    }
    if (d[i] == 'U')
    {
      ta = r1 - l[i];
      if (ys.count(c1) == 0)
      {
        r1 = max(ta, 0ll);
        cout << r1 + 1 << " " << c1 + 1 << endl;
        continue;
      }
      int f = -2;
      if (ys[c1].count(r1) == 0)
      {
        f = r1;
        ys[c1].insert(r1);
      }
      auto p = ys[c1].find(r1);
      p--;

      if (ta <= *p)
      {
        r1 = *p + 1;
      }
      else
      {
        r1 = ta;
      }

      if (f != -2)
      {
        ys[c1].erase(f);
      }
    }
    else if (d[i] == 'D')
    {
      ta = r1;
      if (ys.count(c1) == 0)
      {
        r1 = min(r1 + l[i], h - 1);
        cout << r1 + 1 << " " << c1 + 1 << endl;

        continue;
      }

      auto p = ys[c1].lower_bound(ta);

      if (*p <= r1 + l[i])
      {
        r1 = *p - 1;
      }
      else
      {
        r1 = r1 + l[i];
      }
    }

    cout << r1 + 1 << " " << c1 + 1 << endl;
  }

  return 0;
}