#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;
VV edge;
V v;
vector<ll> t;

ll dfs(int ptr)
{
  v[ptr] = 1;
  if (edge[ptr].size() == 0)
  {
    return t[ptr];
  }
  ll sum = 0;
  REPR(j, edge[ptr].size())
  {
    if (v[edge[ptr][j]] == 0)
    {
      sum += dfs(edge[ptr][j]);
    }
  }
  return sum + t[ptr];
}

int main()
{
  int n;
  cin >> n;
  t.resize(n + 1);
  v.resize(n + 1);
  edge.resize(n + 1);
  REP2(i, 1, n + 1)
  {
    v[i] = 0;
    cin >> t[i];
    int tmp;
    cin >> tmp;
    edge[i].resize(tmp);
    REP(j, tmp)
    {
      int a;
      cin >> a;
      edge[i][j] = a;
    }
  }

  REP(i, n)
  {
    sort(edge[i].begin(), edge[i].end());
  }

  cout << dfs(n) << endl;

  return 0;
}