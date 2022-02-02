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
using VVV = vector<vector<vector<int>>>;
using P = pair<int, int>;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int h, w;
  cin >> h >> w;
  P s, t;
  cin >> s.first >> s.second;
  cin >> t.first >> t.second;

  vector<vector<char>> S(h + 2, vector<char>(w + 2));
  REP(i, h + 2)
  {
    REP(j, w + 2)
    {
      if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
      {
        S[i][j] = '#';
      }
      else
      {
        cin >> S[i][j];
      }
    }
  }

  VVV cnt(h + 1, VV(w + 1, V(4, INF)));

  P ad[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

  queue<P> que;
  que.push(make_pair(s.first, s.second));
  S[s.first][s.second] = '#';
  cnt[s.first][s.second][0] = 0;
  cnt[s.first][s.second][1] = 0;
  cnt[s.first][s.second][2] = 0;
  cnt[s.first][s.second][3] = 0;
  P ptr;

  while (que.size())
  {
    ptr = que.front();
    que.pop();
    REP(i, 4)
    {
      if (S[ptr.first + ad[i].first][ptr.second + ad[i].second] == '.')
      {
        REP(j, 4)
        {
          if (i == j)
          {
            if (cnt[ptr.first + ad[i].first][ptr.second + ad[i].second][j] > cnt[ptr.first][ptr.second][i])
            {
              que.push(make_pair(ptr.first + ad[i].first, ptr.second + ad[i].second));
              cnt[ptr.first + ad[i].first][ptr.second + ad[i].second][j] = cnt[ptr.first][ptr.second][i];
            }
          }
          else
          {
            if (cnt[ptr.first + ad[i].first][ptr.second + ad[i].second][j] > cnt[ptr.first][ptr.second][i] + 1)
            {
              que.push(make_pair(ptr.first + ad[i].first, ptr.second + ad[i].second));
              cnt[ptr.first + ad[i].first][ptr.second + ad[i].second][j] = cnt[ptr.first][ptr.second][i] + 1;
            }
          }
        }
      }
    }
  }

  cout << min(min(min(cnt[t.first][t.second][0], cnt[t.first][t.second][1]), cnt[t.first][t.second][2]), cnt[t.first][t.second][3]) << endl;
  return 0;
}

// pushのタイミングが条件分岐に変わる．