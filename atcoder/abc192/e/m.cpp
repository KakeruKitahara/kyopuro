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
using ll = long long;
using Vl = vector<ll>;
using VVl = vector<vector<ll>>;
using VVVl = vector<vector<vector<ll>>>;
using P = pair<ll, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
constexpr int IINF = 1000000000 + 8;
constexpr ll LINF = 1000000000000000000LL + 8;
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

struct Edge
{
  ll to;
  ll cost;
};

using Wedge = vector<vector<Edge>>;

void dijkstra(Wedge g, Wedge k, int s, Vl &dis)
{
  int N = g.size();
  dis.resize(N, LINF);
  priority_queue<P, vector<P>, greater<P>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty())
  {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first)
    {
      continue;
    }
    REP(i, g[v].size())
    {
      ll time = k[v][i].cost - (dis[v] % k[v][i].cost);
      if (time == k[v][i].cost)
      {
        time = 0;
      }
      if (dis[g[v][i].to] > time + dis[v] + g[v][i].cost)
      {
        dis[g[v][i].to] = time + dis[v] + g[v][i].cost;
        pq.emplace(dis[g[v][i].to], g[v][i].to);
      }
    }
  }
}

int main()
{
  int n, m, x, y;
  cin >> n >> m >> x >> y;

  Wedge g(n), k(n);
  REP(i, m)
  {
    int a, b, t, k2;
    cin >> a >> b >> t >> k2;
    Edge tmp;
    tmp.cost = t;
    tmp.to = b - 1;
    g[a - 1].push_back(tmp);
    tmp.to = a - 1;
    g[b - 1].push_back(tmp);
    tmp.cost = k2;
    k[b - 1].push_back(tmp);
    tmp.to = b - 1;
    k[a - 1].push_back(tmp);
  }

  Vl dis;
  dijkstra(g, k, x - 1, dis);
  if (dis[y - 1] == LINF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << dis[y - 1] << endl;
  }

  return 0;
}