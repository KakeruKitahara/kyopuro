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
  int t;
  cin >> t;
  VV rgb(t, V(3));

  REP(i, t)
  {
    cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
  }

  int rg, gb, br;

  REP(i, t)
  {
    rg = abs(rgb[i][0] - rgb[i][1]);
    gb = abs(rgb[i][1] - rgb[i][2]);
    br = abs(rgb[i][2] - rgb[i][0]);

    int mins = IINF;
    if (rg % 3 != 0 && gb % 3 != 0 && br % 3 != 0)
    {
      cout << -1 << endl;
    }
    else
    {
      if (rg % 3 == 0)
      {
        int tmp = rg / 3;
        mins = min(mins, min(rgb[i][0], rgb[i][1]) + tmp * 2 + tmp);
      }
      if (gb % 3 == 0)
      {
        int tmp = gb / 3;
        mins = min(mins, min(rgb[i][1], rgb[i][2]) + tmp * 2 + tmp);
      }
      if (br % 3 == 0)
      {
        int tmp = br / 3;
        mins = min(mins, min(rgb[i][2], rgb[i][0]) + tmp * 2 + tmp);
      }
      cout << mins << endl;
    }
  }

  return 0;
}