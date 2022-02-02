#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF 1e9

const int MAXN = 16;
int n;
int d[MAXN][MAXN];
pair<int, string> dp[1 << MAXN][MAXN];
vector<char> c;

pair<int, string> rec(int S, int v)
{
  if (dp[S][v].first >= 0)
    return dp[S][v];
  if (S == (1 << n) - 1 && v == 0)
  {
    dp[S][v].first = 0;
    return dp[S][v];
  }
  pair<int, string> tmp, b;
  tmp.first = INF;
  REP(u, n)
  if (!(S >> u & 1))
  {
    b = rec(S | 1 << u, u);
    b.first += d[v][u];
    b.second += c[u];
    if (b.first < tmp.first)
    {
      tmp = b;
    }
  }
  return dp[S][v] = tmp;
}

int main()
{

  int m, s;
  cin >> n >> s;
  c.resize(n);
  REP(i, n)
  cin >> c[i];
  swap(c[0], c[s]);
  cin >> m;
  REP(i, n)
  REP(j, n)
  d[i][j] = d[j][i] = INF;
  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == s)
      a = 0;
    else if (a == 0)
      a = s;
    if (b == 0)
      b = s;
    else if (b == s)
      b = 0;
    d[a][b] = c;
  }

  REP(i, 1 << MAXN)
  REP(j, MAXN)
  dp[i][j].first = -1;
  dp[0][0].second = c[0];
  rec(0, 0);
  cout << dp[0][0].first << endl;
  dp[0][0].second += c[0];
  reverse(dp[0][0].second.begin(), dp[0][0].second.end());
  cout << dp[0][0].second << endl;
  return 0;
}