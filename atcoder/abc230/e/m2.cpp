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

  ll n;
  cin >> n;
  ll ans = 0;

  Vl d, d2;
  d.push_back(0);
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      d.push_back(i);
      if (i * i != n)
        d2.push_back(n / i);
    }
  }

  REPR(i, d2.size())
  {
    d.push_back(d2[i]);
  }

  REP(i, d.size() - 1)
  {
    ans += (d[i + 1] - d[i]) * d[d.size() - 1 - i];
    if (d[d.size() - 1 - i] - d[d.size() - i - 2] >= 2)
    {
      int t;
      REP2(j, d[i + 1] + 1, d[i + 2])
      {
        if (j != 0)
        {
          t = j;
          if (n / j == d[d.size() - i - 2])
          {
            break;
          }
          ans += n / j;
        }
      }
      ans -= (t - d[i + 1] - 1) * d[d.size() - i - 2];
    }
  }

  cout << ans << endl;

  return 0;
}