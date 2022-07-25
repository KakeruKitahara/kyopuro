#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

VS s;
P d;
int ans, h, w2;

void dfs(P p, VS ms, int cnt)
{

  if (p.first == d.first && p.second == d.second)
  {
    ans = min(ans, cnt);
    return;
  }
  ms[p.second][p.first] = '#';
  int cx = 0, cy = 0;
  REP2(i, -2, 3)
  {
    REP2(j, -2, 3)
    {
      if (0 <= p.second + i && p.second + i < h && 0 <= p.first + j && p.first + j < w2)
      {
        if (ms[p.second + i][p.first + j] == '.')
        {
          dfs(make_pair(p.first + j, p.second + i), ms, cnt + 1);
        }
      }
    }
  }

  P w[4] = {make_pair(-1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(1, 0)};

  REP(i, 4)
  {
    if (0 <= p.second + w[i].first && p.second + w[i].first < h && 0 <= p.first + w[i].second && p.first + w[i].second < w2)
    {
      if (ms[p.second + w[i].first][p.first + w[i].second] == '.')
      {
        dfs(make_pair(p.first + w[i].second, p.second + w[i].first), ms, cnt);
      }
    }
  }

  ms[p.second][p.first] = '.';
  return;
}

int main()
{
  cin >> h >> w2;
  P c;
  cin >> c.first >> c.second;
  cin >> d.first >> d.second;
  c.first--;
  c.second--;
  d.first--;
  d.second--;

  s.resize(h);
  REP(i, h)
  {
    cin >> s[i];
  }
  ans = IINF;

  dfs(c, s, 0);

  if (IINF == ans)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }

  return 0;
}