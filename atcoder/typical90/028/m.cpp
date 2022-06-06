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
  int n;
  cin >> n;

  VV map(1001, V(1001));
  V ans(n);

  REP(i, n)
  {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    map[y1][x1]++;
    map[y2][x1]--;
    map[y1][x2]--;
    map[y2][x2]++;
  }

  REP2(i, 0, 1001)
  {
    REP2(j, 1, 1001)
    {
      map[i][j] += map[i][j - 1];
    }
  }

  REP2(i, 1, 1001)
  {
    REP2(j, 0, 1001)
    {
      map[i][j] += map[i - 1][j];
    }
  }

  REP(i, 1001)
  {
    REP(j, 1001)
    {
      if (map[i][j] != 0)
      {
        ans[map[i][j] - 1]++;
      }
    }
  }

  REP(i, n)
  {
    cout << ans[i] << endl;
  }

  return 0;
}