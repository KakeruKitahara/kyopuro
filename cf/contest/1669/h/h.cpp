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

int main()
{
  int t;
  cin >> t;
  V n(t), k(t);
  VVl a(t);
  REP(i, t)
  {
    cin >> n[i] >> k[i];
    a[i].resize(n[i]);
    REP(j, n[i])
    {
      cin >> a[i][j];
    }
  }

  REP(i, t)
  {
    VV one(32);
    V f(32);

    REP(j, n[i])
    {
      int tm = a[i][j];
      int c = 0;
      while (tm != 0)
      {
        if (tm & 1 == 1)
        {
          one[c].push_back(j);
        }
        tm = tm >> 1;
        c++;
      }
    }

    REPR(j, 31)
    {
      if (one[j].size() + k[i] >= a[i].size())
      {
        k[i] -= (a[i].size() - one[j].size());
        f[j] = 1;
      }
    }
    ll ans = 0;
    REPR(j, 31)
    {
      if (f[j] == 1)
      {
        ans = ans | 1;
      }
      if (j == 0)
      {
        break;
      }
      ans = ans << 1;
    }

    cout << ans << endl;
  }

  return 0;
}