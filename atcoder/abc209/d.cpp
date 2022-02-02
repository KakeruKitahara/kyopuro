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

int main()
{
  int n, q;
  cin >> n >> q;
  VV e(n + 1);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  V c(q), d(q);
  REP(i, q)
  {
    cin >> c[i] >> d[i];
  }

  queue<int> que;
  V bo(n);
  V dist(n);
  que.push(1);
  bo[1] = 1;
  while (que.size())
  {
    int ptr = que.front();
    que.pop();
    REP(i, e[ptr].size())
    {
      if (bo[e[ptr][i]] == 0)
      {
        que.push(e[ptr][i]);
        dist[e[ptr][i]] = dist[ptr] + 1;
        bo[e[ptr][i]] = 1;
      }
    }
  }

  REP(i, q)
  {
    if (abs(dist[c[i]] - dist[d[i]]) % 2)
    {
      cout << "Road" << endl;
    }
    else
    {
      cout << "Town" << endl;
    }
  }

  return 0;
}