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

struct UnionFind
{ // The range of node number is u 0 v n-1
  vector<int> rank, parents;
  UnionFind() {}
  UnionFind(int n)
  { // make n trees.
    rank.resize(n, 0);
    parents.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
      makeTree(i);
    }
  }
  void makeTree(int x)
  {
    parents[x] = x; // the parent of x is x
    rank[x] = 0;
  }
  bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
  void unite(int x, int y)
  {
    x = findRoot(x);
    y = findRoot(y);
    if (rank[x] > rank[y])
    {
      parents[y] = x;
    }
    else
    {
      parents[x] = y;
      if (rank[x] == rank[y])
      {
        rank[y]++;
      }
    }
  }
  int findRoot(int x)
  {
    if (x != parents[x])
      parents[x] = findRoot(parents[x]);
    return parents[x];
  }
};

// 辺の定義
struct Edge
{
  long long u;
  long long v;
  long long cost;
};

bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数

int cc;
struct Kruskal
{
  UnionFind uft;
  long long sum; // 最小全域木の重みの総和
  vector<Edge> edges;
  int V;
  Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
  void init()
  {
    sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
    uft = UnionFind(V);
    sum = 0;
    for (auto e : edges)
    {
      if (e.cost < 0)
      {
        uft.unite(e.u, e.v);
        sum += e.cost;
        continue;
      }
      if (!uft.isSame(e.u, e.v))
      { // 閉路にならなければ加える
        uft.unite(e.u, e.v);
        sum += e.cost;
      }
    }
  }
};

int main()
{
  int V, E;
  cin >> V >> E;
  vector<Edge> edges(E);
  ll mins = 0;
  ll sum = 0;
  for (int i = 0; i < E; i++)
  {
    long long s, t, w;
    cin >> s >> t >> w;
    t--;
    s--;
    Edge e = {s, t, w};
    edges[i] = e;
    mins = min(mins, w);
  }

  cc = 0;

  for (auto &p : edges)
  {
    sum += p.cost;
  }

  Kruskal krs(edges, V);
  cout << sum - krs.sum << endl;
  return 0;
}