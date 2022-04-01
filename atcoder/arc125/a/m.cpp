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
  int n, m;
  cin >> n >> m;
  V a(n), c(m);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, m)
  {
    cin >> c[i];
  }

  V cnt(2), jd(2);
  REP(i, m)
  {
    cnt[c[i]] = 1;
  }

  REP(i, n)
  {
    jd[a[i]] = 1;
  }

  REP(i, 2)
  {
    if (cnt[i] == 1 && jd[i] == 0)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  V b;
  int s = a[0];

  int ii = 1, jj = 1;
  while (s == a[ii])
  {
    ii++;
    if (ii == n)
      break;
  }
  while (s == a[n - jj])
  {
    jj++;
    if (n - jj == 0)
      break;
  }

  ll ans = 0;
  int f = 1;
  REP(i, m)
  {
    if (c[i] == s)
    {
      ans++;
    }
    else
    {
      if (f)
      {
        ans += min(ii, jj) + 1;
        f = 0;
        s = c[i];
      }
      else
      {
        ans += 2;
        s = c[i];
      }
    }
  }

  cout << ans << endl;

  return 0;
}