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

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;

  VV dis(n, V(n, IINF));
  V ans(n - 1);

  REP(i, n)
  {
    queue<P> q;
    V jd(n);
    jd[i] = 1;
    q.push(make_pair(i, 0));

    while (q.size() != 0)
    {
      P p = q.front();
      q.pop();

      if (p.first != 0 && jd[p.first - 1] == 0)
      {
        if (dis[min(i, p.first - 1)][max(i, p.first - 1)] > p.second + 1)
        {
          dis[min(i, p.first - 1)][max(i, p.first - 1)] = p.second + 1;
        }
        jd[p.first - 1] = 1;
        q.push(make_pair(p.first - 1, p.second + 1));
      }

      if (p.first != n - 1 && jd[p.first + 1] == 0)
      {
        if (dis[min(i, p.first + 1)][max(i, p.first + 1)] > p.second + 1)
        {
          dis[min(i, p.first + 1)][max(i, p.first + 1)] = p.second + 1;
        }
        jd[p.first + 1] = 1;
        q.push(make_pair(p.first + 1, p.second + 1));
      }
      if (p.first == x && jd[y] == 0)
      {
        if (dis[min(i, y)][max(i, y)] > p.second + 1)
        {
          dis[min(i, y)][max(i, y)] = p.second + 1;
        }
        jd[y] = 1;
        q.push(make_pair(y, p.second + 1));
      }

      if (p.first == y && jd[x] == 0)
      {
        if (dis[min(i, x)][max(i, x)] > p.second + 1)
        {
          dis[min(i, x)][max(i, x)] = p.second + 1;
        }
        jd[x] = 1;
        q.push(make_pair(x, p.second + 1));
      }
    }
  }

  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      ans[dis[i][j] - 1]++;
    }
  }

  REP(i, n - 1)
  {
    cout << ans[i] << endl;
  }
  return 0;
}