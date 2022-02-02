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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n, m;
  cin >> n >> m;
  VV e(n + 1);
  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  V bo(n + 1);
  V dist(n + 1);
  queue<int> q;
  q.push(1);
  bo[1] = 1;
  vector<mint> ans(n + 1);
  ans[1] = 1;

  while (q.size())
  {
    int ptr = q.front();
    q.pop();
    REP(i, e[ptr].size())
    {
      if (dist[e[ptr][i]] == dist[ptr] + 1)
      {
        ans[e[ptr][i]] += ans[ptr];
      }
      if (bo[e[ptr][i]] == 0)
      {
        q.push(e[ptr][i]);
        bo[e[ptr][i]] = 1;
        if (dist[e[ptr][i]] != dist[ptr] + 1)
        {
          ans[e[ptr][i]] = ans[ptr];
        }
        dist[e[ptr][i]] = dist[ptr] + 1;
      }
    }
  }

  cout << ans[n].val() << endl;

  return 0;
}