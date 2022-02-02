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

VV d;

ll p(int x, int y, int x2, int y2, ll cnt)
{
  int diff = d[x2][y2];
  REP2(i, x, x + 2)
  {
    REP2(j, y, y + 2)
    {
      d[i][j] -= diff;
    }
  }
  cnt += abs(diff);
  return cnt;
}

int main()
{
  int h, w;
  cin >> h >> w;
  VV a(h, V(w)), b(h, V(w));
  REP(i, h)
  {
    REP(j, w)
    {
      cin >> a[i][j];
    }
  }
  REP(i, h)
  {
    REP(j, w)
    {
      cin >> b[i][j];
    }
  }

  d.resize(h);
  REP(i, h)
  {
    d[i].resize(w);
  }

  REP(i, h)
  {
    REP(j, w)
    {
      d[i][j] = a[i][j] - b[i][j];
    }
  }

  ll cnt = 0;

  cnt = p(0, 0, 0, 0, cnt);
  cnt = p(0, w - 2, 0, w - 1, cnt);
  cnt = p(h - 2, 0, h - 1, 0, cnt);
  cnt = p(h - 2, w - 2, h - 1, w - 1, cnt);

  REP2(i, 1, h - 2)
  {
    cnt = p(i, 0, i, 0, cnt);
    cnt = p(i, w - 2, i, w - 1, cnt);
  }

  REP2(i, 1, w - 2)
  {
    cnt = p(h - 2, i, h - 1, i, cnt);
    cnt = p(0, i, 0, i, cnt);
  }

  REP2(i, 1, h - 2)
  {
    REP2(j, 1, w - 2)
    {
      cnt = p(i, j, i, j, cnt);
    }
  }

  REP(i, h)
  {
    REP(j, w)
    {
      if (d[i][j] != 0)
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  cout << cnt << endl;

  return 0;
}