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

struct edge
{
  int to;
  int cost;
};
vector<int> dijkstra(vector<vector<edge>> graph, int n, int start)
{
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> dst(n, IINF);
  dst[start] = 0;
  que.push(P(0, start));
  while (que.size())
  {
    int d = que.top().first;
    int u = que.top().second;
    que.pop();
    if (dst[u] < d)
      continue;
    for (int i = 0; i < graph[u].size(); ++i)
    {
      int v = graph[u][i].to;
      int cost = graph[u][i].cost;
      if (dst[v] > d + cost)
      {
        dst[v] = d + cost;
        que.push(P(dst[v], v));
      }
    }
  }
  return dst;
}

int main()
{
  int n, m;
  cin >> n >> m;
  V c(n);
  vector<vector<edge>> ed(n);
  vector<set<int>> ed2(n);
  vector<map<int, int>> ed3(n);
  V my(n, IINF);
  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b;
    cin >> c;

    if (a == b)
    {
      my[a - 1] = min(my[a - 1], c);
      continue;
    }

    if (ed2[b - 1].count(a - 1) == false)
    {
      ed3[a - 1][b - 1] = c;
      ed2[b - 1].insert(a - 1);
      continue;
    }

    if (ed2[b - 1].count(a - 1) == true && ed3[a - 1][b - 1] > c)
    {
      ed3[a - 1][b - 1] = c;
      ed2[b - 1].insert(a - 1);
    }
  }

  REP(i, n)
  {
    for (auto p : ed3[i])
    {
      edge t;
      t.to = p.first;
      t.cost = p.second;
      ed[i].push_back(t);
    }
  }

  REP(i, n)
  {
    V ds = dijkstra(ed, n, i);
    int ans = my[i];
    for (int p : ed2[i])
    {
      ans = min(ds[p] + ed3[p][i], ans);
    }
    if (ans == IINF)
    {
      cout << -1 << endl;
    }
    else
      cout << ans << endl;
  }

  return 0;
}