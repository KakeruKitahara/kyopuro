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
using mint = modint998244353;

int main()
{
  int n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  VV edge(n + 1);
  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  vector<vector<mint>> dpo(k + 1, vector<mint>(n + 1));
  vector<vector<mint>> dpe(k + 1, vector<mint>(n + 1));

  dpe[0][s] = 1;

  vector<set<int>> in(k + 1);
  REP(i, edge[s].size())
  {
    dpo[1][edge[s][i]] += dpo[0][s];
    dpe[1][edge[s][i]] += dpe[0][s];
    in[1].insert(edge[s][i]);
  }

  REP2(i, 1, k)
  {
    for (int j : in[i])
    {
      int ptr = j;
      if (ptr == x)
      {
        swap(dpe[i][ptr], dpo[i][ptr]);
      }
      REP(l, edge[ptr].size())
      {
        dpo[i + 1][edge[ptr][l]] += dpo[i][ptr];
        dpe[i + 1][edge[ptr][l]] += dpe[i][ptr];
        in[i + 1].insert(edge[ptr][l]);
      }
    }
  }

  cout << dpe[k][t].val() << endl;

  return 0;
}