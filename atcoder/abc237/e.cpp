#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

struct Edge
{
  long long from;
  long long to;
  long long cost;
};
using Edges = vector<Edge>;
const long long INF = 1LL << 60;
bool bellman_ford(const Edges &Es, int V, int s, vector<long long> &dis)
{
  dis.resize(V, INF);
  dis[s] = 0;
  int cnt = 0;
  while (cnt < V)
  {
    bool end = true;
    for (auto e : Es)
    {
      if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to])
      {
        dis[e.to] = dis[e.from] + e.cost;
        end = false;
      }
    }
    if (end)
      break;
    cnt++;
  }
  return (cnt == V);
}

int main()
{
  int n, m;
  V h(n);
  REP(i, n)
  {
    cin >> h[i];
  }
  V u(m), v(m);
  REP(i, m)
  {
    cin >> u[i] >> v[i];
  }

  return 0;
}