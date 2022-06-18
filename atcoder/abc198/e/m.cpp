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
V ans;
V jd;
set<int> ind;
VV edge;
V c;

void dfs(int ptr)
{
  int f = 0;

  jd[ptr] = 1;
  if (ind.count(c[ptr]) == 0)
  {
    f = 1;
    ind.insert(c[ptr]);
    ans[ptr] = 1;
  }

  REP(i, edge[ptr].size())
  {
    if (jd[edge[ptr][i]] == 0)
    {
      dfs(edge[ptr][i]);
    }
  }

  if (f == 1)
  {
    ind.erase(c[ptr]);
  }

  return;
}

int main()
{
  int n;
  cin >> n;
  c.resize(n);
  REP(i, n)
  {
    cin >> c[i];
  }

  edge.resize(n);
  ans.resize(n);
  jd.resize(n);

  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  dfs(0);

  REP(i, n)
  {
    if (ans[i] == 1)
    {
      cout << i + 1 << endl;
    }
  }

  return 0;
}