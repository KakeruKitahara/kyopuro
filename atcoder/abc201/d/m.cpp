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
  vector<S> s(h);
  REP(i, h)
  {

    cin >> s[i];
  }

  REP(i, h)
  {
    REP(j, w)
    {
      char c = s[i][j];
      if (c == '+')
      {
        a[i][j] = 1;
      }
      else
      {
        a[i][j] = -1;
      }
      if ((i + j) % 2 == 0)
      {
        a[i][j] = -a[i][j];
      }
    }
  }

  VV dp(h, V(w));
  REPR(i, h)
  {
    REPR(j, w)
    {
      if (i == h - 1 && j == w - 1)
        continue;
      if (i == h - 1)
      {
        dp[i][j] = dp[i][j + 1] + a[i][j + 1];
      }
      else
      {
        if (j == w - 1)
        {
          dp[i][j] = dp[i + 1][j] + a[i + 1][j];
        }
        else
        {
          if ((i + j) % 2 == 0)
          {
            dp[i][j] = max(dp[i + 1][j] + a[i + 1][j], dp[i][j + 1] + a[i][j + 1]);
          }
          else
          {
            dp[i][j] = min(dp[i + 1][j] + a[i + 1][j], dp[i][j + 1] + a[i][j + 1]);
          }
        }
      }
    }
  }

  if (dp[0][0] > 0)
  {
    cout << "Takahashi" << endl;
  }
  else if (dp[0][0] < 0)
  {
    cout << "Aoki" << endl;
  }
  else
  {
    cout << "Draw" << endl;
  }

  return 0;
}