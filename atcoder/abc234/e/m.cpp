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
  ll x;
  cin >> x;
  ll tx = x;
  int cnt = 0;
  int d = 0;
  while (1)
  {
    tx /= 10;
    cnt++;
    if (tx / 10 == 0)
    {
      d = tx;
      cnt++;
      break;
    }
  }

  REP(l, 2)
  {
    d += l;
    int ab = 9 / (cnt - 1);
    ll ans = -1;

    REP2(i, -ab, ab + 1)
    {
      int f = 0;
      V nums(cnt);
      nums[0] = d;
      REP2(j, 1, cnt)
      {
        nums[j] = nums[j - 1] + i;
        if (nums[j] < 0 || 9 < nums[j])
        {
          f = 1;
          break;
        }
      }
      if (f == 1)
        continue;

      ll p = 0;
      ll d2 = 1;
      REPR(i, cnt)
      {
        p += d2 * nums[i];
        d2 *= 10;
      }

      if (p >= x)
      {
        ans = p;
        cout << ans << endl;
        return 0;
      }
    }
  }

  return 0;
}