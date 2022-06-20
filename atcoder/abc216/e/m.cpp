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
  ll n, k;
  cin >> n >> k;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  Vl s;
  REP2(i, 1, n)
  {
    ll b;
    b = a[i - 1] - a[i];
    s.push_back(b);
  }

  ll ans = 0;

  if (s.size() > 0)
  {

    Vl sum(n - 1);
    sum[0] = s[0];
    REP2(i, 1, n - 1)
    {
      sum[i] = sum[i - 1] + (i + 1) * s[i];
    }

    auto p = lower_bound(sum.begin(), sum.end(), k);
    int m = p - sum.begin();

    REP(i, m)
    {
      k -= (i + 1) * s[i];
      ans += (i + 1) * (s[i] * ((a[i] - s[i] + 1) + a[i])) / 2;
    }

    ll am = a[m];

    int f = 0;
    if (k > 0)
    {
      REP(i, k / (m + 1))
      {
        ans += (m + 1) * am;
        am--;
        if (am == 0)
        {
          f = 1;
          break;
        }
      }
      if (f == 0)
        ans += (k % (m + 1)) * am;
    }
  }
  else
  {
    if (k - a[0] < 0)
    {
      ans += (k * ((a[0] - k + 1) + a[0])) / 2;
    }
    else
    {
      ans += a[0] * (a[0] + 1) / 2;
    }
  }

  cout << ans << endl;

  return 0;
}