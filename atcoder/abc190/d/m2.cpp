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
  vector<ll> k;
  ll ans = 0;
  ll p = n;
  if (n % 2 == 0)
  {
    for (ll i = 1; i * i <= p; i++)
    {
      if (p % i == 0)
      {
        k.push_back(i);
        if (i * i != p)
          k.push_back(p / i);
      }
    }

    REP(i, k.size())
    {
      if (k[i] % 2 == 1)
      {
        ans += 2;
      }
    }
  }
  else
  {
    for (ll i = 2; i <= n; i += 2)
    {
      if (p % i == 0)
      {
        k.push_back(i);
        if (i * i != p)
          k.push_back(p / i);
      }
    }
  }

  cout << ans << endl;
  return 0;
}