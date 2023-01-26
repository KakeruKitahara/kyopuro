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
using Pl = pair<long long, long long>;
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

/* dikstra */
void dijkstra(VVP graph, int s, Vl &dis)
{
  dis.resize(graph.size(), LINF);
  priority_queue<Pl, vector<Pl>, greater<Pl>> pq;
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
    for (auto &e : graph[v])
    { // first : to, second : cost
      if (dis[e.first] > dis[v] + e.second)
      {
        dis[e.first] = dis[v] + e.second;
        pq.emplace(dis[e.first], e.second);
      }
    }
  }
}

void dijkstra(VVP graph, int s, Vl dis, V &prev)
{
  dis.resize(graph.size(), LINF);
  prev.resize(graph.size(), -1);
  priority_queue<Pl, vector<Pl>, greater<Pl>> pq;
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
    for (auto &e : graph[v])
    {
      if (dis[e.first] > dis[v] + e.second)
      {
        dis[e.first] = dis[v] + e.second;
        prev[e.first] = v;
        pq.emplace(dis[e.first], e.second);
      }
    }
  }
}

V get_dikstra_path(const V prev, int t)
{
  V path;
  for (int cur = t; cur != -1; cur = prev[cur])
  {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());
  return path;
}

int main()
{
  int n, x;
  cin >> n >> x;
  V a(n), b(n);
  REP(i, n)
  {
    cin >> a[i] >> b[i];
  }
  VV dp(51, V(10001));
  dp[0][0] = 1;

  REP2(i, 1, n + 1)
  {
    REP2(j, 1, b[i - 1] + 1)
    {
      REP(k, 10001)
      {
        if (k - a[i - 1] * j >= 0)
        {
          dp[i][k] = max(dp[i][k], max(dp[i - 1][k], dp[i - 1][k - a[i - 1] * j]));
        }
        else{
          dp[i][k] = max(dp[i - 1][k], dp[i][k]);
        }
      }
    }
  }

  if (dp[n][x] == 1)
  {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
