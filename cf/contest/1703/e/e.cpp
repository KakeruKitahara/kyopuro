#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
  int n;
  cin >> n;
  vector<VV> a(4, VV(n, V(n)));
  vector<S> s(n);

  REP(i, n)
  {
    cin >> s[i];
  }
  REP(i, n)
  {
    REP(j, n)
    {
      a[0][i][j] = s[i][j] - '0';
    }
  }

  REP(i, 3)
  {
    REP(j, n)
    {
      REP(k, n)
      {
        a[i + 1][j][k] = a[i][k][n - 1 - j];
      }
    }
  }
  int ans = 0;
  REP(i, n)
  {
    REP(j, n)
    {
      int z = 0, o = 0;
      REP(k, 4)
      {
        if (a[k][i][j] == 0)
        {
          z++;
        }
        else
        {
          o++;
        }
      }
      ans += min(z, o);
    }
  }

  cout << ans / 4 << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}