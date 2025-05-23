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
  int h, w;
  cin >> h >> w;
  VV a(h, V(w));
  REP(i, h)
  {
    REP(j, w)
    {
      cin >> a[i][j];
    }
  }

  REP(i, h)
  {
    REP2(i2, i + 1, h)
    {
      REP(j, w)
      {
        REP2(j2, j + 1, w)
        {
          if (a[i][j] + a[i2][j2] > a[i2][j] + a[i][j2])
          {
            cout << "No" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}