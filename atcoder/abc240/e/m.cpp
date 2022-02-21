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
VV e;
vector<P> lr;
int o;
V bo;

P dfs2(int ptr)
{
  bo[ptr] = 1;

  if (e[ptr].size() == 1)
  {
    o++;
    lr[ptr] = make_pair(o, o);
    return lr[ptr];
  }

  P t = make_pair(IINF, -1), tmp;
  REP(i, e[ptr].size())
  {
    if (bo[e[ptr][i]] == 1)
    {
      continue;
    }
    tmp = dfs2(e[ptr][i]);
    t.first = min(tmp.first, t.first);
    t.second = max(tmp.second, t.second);
  }
  lr[ptr] = t;
  return t;
}

P dfs1(int ptr)
{
  bo[ptr] = 1;
  P t = make_pair(IINF, -1), tmp;
  REP(i, e[ptr].size())
  {
    if (bo[e[ptr][i]] == 1)
    {
      continue;
    }
    tmp = dfs2(e[ptr][i]);
    t.first = min(tmp.first, t.first);
    t.second = max(tmp.second, t.second);
  }
  lr[ptr] = t;
  return t;
}

int main()
{
  int n;
  cin >> n;
  e.resize(n + 1);
  lr.resize(n + 1);
  bo.resize(n + 1);
  o = 0;
  REP(i, n - 1)
  {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  dfs1(1);

  REP2(i, 1, n + 1)
  {
    cout << lr[i].first << " " << lr[i].second << endl;
  }

  return 0;
}