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
  V h(3), w(3);
  REP(i, 3)
  {
    cin >> h[i];
  }
  REP(i, 3)
  {
    cin >> w[i];
  }

  ll ans = 0;

  REP2(i, 1, w[0])
  {
    REP2(ii, 1, w[0])
    {
      if (i + ii >= w[0])
      {
        continue;
      }

      int iii = w[0] -i - ii;

      REP2(j, 1, w[1])
      {
        REP2(jj, 1, w[1])
        {
          if (j + jj >= w[1])
          {
            continue;
          }
          int jjj = w[1] - j - jj;

          REP2(k, 1, w[2])
          {
            REP2(kk, 1, w[2])
            {
              if (k + kk >= w[2])
              {
                continue;
              }

              int kkk = w[2] - k - kk;

              if (i + j + k == h[0] && ii + jj + kk == h[1] && iii + jjj + kkk == h[2])
              {
                ans++;
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