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
  int h, w;
  cin >> h >> w;
  vector<S> map(h);
  REP(i, h)
  {
    REP(j, w)
    {
      char a;
      cin >> a;
      map[i].push_back(a);
    }
  }

  // (y, x)となる．
  P walk[4] = {make_pair(-1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(1, 0)};

  int ans = -1;
  REP(i, h)
  {
    REP(j, w)
    {
      if (map[i][j] == '.')
      {
        vector<S> map2 = map;
        queue<P> que;
        que.push(make_pair(i, j));
        int cnt = -1;
        while (que.size() != 0)
        {
          cnt++;
          P xy = que.front();
          if (cnt == 0)
          {
            map2[xy.first][xy.second] = '#';
          }
          que.pop();
          REP(k, 4)
          {
            P xy2;
            xy2.first = xy.first + walk[k].first;
            xy2.second = xy.second + walk[k].second;
            if (0 <= xy2.first && xy2.first < h && 0 <= xy2.second && xy2.second < w)
            {
              if (map2[xy2.first][xy2.second] == '.')
              {
                que.push(xy2);
              }
              if (xy2.first == i && xy2.second == j)
              {
                ans = max(ans, cnt);
              }
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}