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

struct HashPair
{

  //注意 constがいる
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {

    // first分をハッシュ化する
    auto hash1 = hash<T1>{}(p.first);

    // second分をハッシュ化する
    auto hash2 = hash<T2>{}(p.second);

    //重複しないようにハッシュ処理
    size_t seed = 0;
    seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};

void dijkstra(vector<vector<P>> &G, int s, vector<long long> &dis, vector<int> &prev)
{
  int N = G.size();
  dis.resize(N, LINF);
  prev.resize(N, -1);
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
    for (auto &e : G[v])
    {
      if (dis[e.first] > dis[v] + e.second)
      {
        dis[e.first] = dis[v] + e.second;
        prev[e.first] = v;
        pq.emplace(dis[e.first], e.first);
      }
    }
  }
}



int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<P>> edge(n + 1);
  unordered_map<P, int, HashPair> road;

  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back(make_pair(b, c));
    edge[b].push_back(make_pair(a, c));
    road[make_pair(a, b)] = i + 1;
    road[make_pair(b, a)] = i + 1;
  }

  Vl dis;
  V path;

  dijkstra(edge, 1, dis, path);

  V ans;

  REP2(i, 2, n + 1)
  {
    ans.push_back(road[make_pair(i, path[i])]);
  }

  REP(i, ans.size())
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}