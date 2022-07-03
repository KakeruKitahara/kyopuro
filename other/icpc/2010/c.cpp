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
V c;
V c2;

void solve(int a)
{

  VV dp(c.size(), V(a + 1));

  REP(i, c.size())
  {
    if (i == 0)
    {
      REPR(j, a + 1)
      {
        dp[0][j] = j;
      }
    }
    else
    {
      REP(j, a + 1)
      {
        if (j - c[i] >= 0)
        {
          dp[i][j] = min(dp[i - 1][j - c[i]] + 1, min(dp[i - 1][j], dp[i][j - c[i]] + 1));
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
  }

  cout << dp[c.size() - 1][a] << " ";

  VV dp2(c2.size(), V(a + 1));
  REP(i, c2.size())
  {
    if (i == 0)
    {
      REPR(j, a + 1)
      {
        dp2[0][j] = j;
      }
    }
    else
    {
      REP(j, a + 1)
      {
        if (j - c2[i] >= 0)
        {
          dp2[i][j] = min(dp2[i - 1][j - c2[i]] + 1, min(dp2[i - 1][j], dp2[i][j - c2[i]] + 1));
        }
        else
        {
          dp2[i][j] = dp2[i - 1][j];
        }
      }
    }
  }

  cout << dp2[c2.size() - 1][a] << endl;
}

int main()
{
  int cnt = 1;
  ll t;
  do
  {
    t = (cnt * (cnt + 1) * (cnt + 2)) / 6;
    c.push_back(t);
    if (t % 2 == 1)
    {
      c2.push_back(t);
    }
    cnt++;
  } while (t <= 1000000);

  while (1)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    solve(a);
  }

  return 0;
}