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
vector<S> c;
pair<int, int> walk[2] = {make_pair(1, 0), make_pair(0, 1)};

int dfs(int pr, int pc)
{
  int f = 0;
  int maxs = -1;
  c[pr][pc] = '#';
  for (int i = 0; i < 2; i++)
  {
    if (c[pr + walk[i].first][pc + walk[i].second] == '.')
    {
      maxs = max(dfs(pr + walk[i].first, pc + walk[i].second), maxs);
    }
  }
  if (maxs == -1)
  {
    return 0;
  }
  return maxs + 1;
}

int main()
{
  int h, w;
  cin >> h >> w;

  c.resize(h + 2);

  for (int i = 0; i < h + 2; i++)
  {
    if (i == 0 || i == h + 1)
    {
      REP(k, w)
      {
        c[i].push_back('#');
      }
    }
    else
    {
      S tm;
      cin >> tm;
      c[i] = "#" + tm + "#";
    }
  }

  int key = dfs(1, 1);
  cout << key + 1 << endl;
  return 0;
}
