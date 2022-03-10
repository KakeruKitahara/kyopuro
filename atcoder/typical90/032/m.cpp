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
  VV a(n, V(n)), e(n);

  REP(i, n)
  {
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  REP(i, m)
  {
    int pa, pb;
    cin >> pa >> pb;
    e[pa - 1].push_back(pb - 1);
    e[pb - 1].push_back(pa - 1);
  }

  V p;
  int ans = IINF;
  REP(i, n)
  p.push_back(i);
  do
  {
    int f = 0;
    REP(i, n)
    {
      if (0 < i)
      {
        REP(j, e[p[i]].size())
        if (p[i - 1] == e[p[i]][j])
        {
          f = 1;
        }
      }
      if (i < n - 1)
      {
        REP(j, e[p[i]].size())
        if (p[i + 1] == e[p[i]][j])
        {
          f = 1;
        }
      }
    }
    if (f == 1)
      continue;

    int tmp = 0;
    REP(i, n)
    {
      tmp += a[p[i]][i];
    }

    ans = min(ans, tmp);

  } while (next_permutation(p.begin(), p.end()));

  if (ans == IINF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}