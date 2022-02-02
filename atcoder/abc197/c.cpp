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

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  ll ans = LINF;
  for (int bit = 0; bit < (1 << n - 1); bit++) // 1 << n = 2^n通り.
  {
    Vl l;
    int s = 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (bit & (1 << i))
      {
        ll sor = 0;
        REP2(j, s, i + 1)
        {
          sor |= a[j];
        }
        s = i + 1;
        l.push_back(sor);
      }
    }
    ll sor = 0;
    REP2(j, s, n)
    {
      sor |= a[j];
    }
    l.push_back(sor);

    ll sxor = l[0];
    REP2(i, 1, l.size())
    {
      sxor ^= l[i];
    }
    ans = sxor < ans ? sxor : ans;
  }
  cout << ans << endl;

  return 0;
}