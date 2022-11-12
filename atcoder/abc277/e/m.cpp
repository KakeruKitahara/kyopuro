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
  int n, m, k;
  cin >> n >> m >> k;

  VVV g(2, VV(n));
  REP(i, m)
  {
    int u, v, a;
    cin >> u >> v >> a;
    if (a == 0)
    {
      g[0][u - 1].push_back(v - 1);
      g[0][v - 1].push_back(u - 1);
    }
    else
    {
      g[1][u - 1].push_back(v - 1);
      g[1][v - 1].push_back(u - 1);
    }
  }
  set<int> s;
  REP(i, k)
  {
    int t;
    cin >> t;
    s.insert(t - 1);
  }

  queue<pair<int, P>> que;
  que.push(make_pair(0, make_pair(0, 1)));
  VV used(2, V(n));
  used[1][0] = 1;

  while (que.size() != 0)
  {

    int ptr = que.front().first;
    int cnt = que.front().second.first;
    int a = que.front().second.second;
    que.pop();

    if (ptr == n - 1)
    {
      cout << cnt << endl;
      return 0;
    }

    REP(i, g[a][ptr].size())
    {
      if (used[a][g[a][ptr][i]] == 0)
      {
        que.push(make_pair(g[a][ptr][i], make_pair(cnt + 1, a)));
        used[a][g[a][ptr][i]] = 1;
      }
    }

    if (s.count(ptr) == 1)
    {
      int b = (a + 1) % 2;
      REP(i, g[b][ptr].size())
      {
        if (used[b][g[b][ptr][i]] == 0)
        {
          que.push(make_pair(g[b][ptr][i], make_pair(cnt + 1, b)));
          used[b][g[b][ptr][i]] = 1;
        }
      }
    }
  }

  cout << -1 << endl;

  return 0;
}