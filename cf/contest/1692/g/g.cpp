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
  VVl a(t);
  V k(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    cin >> k[i];
    a[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }

  REP(i, t)
  {
    int ans = 0;
          int cnt = 0;
    REP(j, a[i].size() - 1)
    {

      if (a[i][j] < 2 * a[i][j + 1])
      {
        cnt++;
      }
      else
      {
        cnt = 0;
      }

      if (cnt >= k[i])
      {
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}