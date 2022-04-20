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
  ll n, k, x;
  cin >> n >> k >> x;

  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  int tmp = IINF;

  REP(i, n)
  {
    if (a[i] / x > k)
    {
      tmp = i;
      break;
    }
    k -= a[i] / x;
    a[i] %= x;
  }

  if (tmp == IINF)
  {

    sort(a.rbegin(), a.rend());

    REP(i, n)
    {
      if (k == 0)
      {
        tmp = i;
        break;
      }
      else
      {
        a[i] = 0;
        k--;
      }
    }
  }

  ll ans = 0;
  REP(i, n)
  {
    if (i == tmp)
    {
      ans += max(a[i] - k * x, 0ll);
    }
    else
    {
      ans += a[i];
    }
  }
  cout << ans << endl;
  return 0;
}