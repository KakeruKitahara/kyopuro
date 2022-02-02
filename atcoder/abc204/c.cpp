#include <bits/stdc++.h>
using namespace std;
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

V used;
VV connect;
VV memo;

int n, m;

int dfs(int now)
{

  if (used[now])
    return 0;
  used[now] = 1;

  int ans = 1;

  for (int a : memo[now])
  {
    ans += dfs(a);
  }

  return ans;
}

int main()
{
  cin >> n >> m;
  V a(m), b(m);
  REP(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  used.resize(n);
  connect.resize(n, V(n));
  memo.resize(n);

  fill(used.begin(), used.end(), 0);
  REP(i, n)
  {
    fill(connect[i].begin(), connect[i].end(), 0);
  }

  for (int i = 0; i < m; i++)
  {
    connect[a[i]][b[i]] = 1;
  }

  REP(i, n)
  {
    REP(j, n)
    {
      if (connect[i][j] == 1)
        memo[i].push_back(j);
    }
  }

  ll sum = 0;
  REP(i, n)
  {
    sum += dfs(i);
    fill(used.begin(), used.end(), 0);
  }

  cout << sum << endl;

  return 0;
}
