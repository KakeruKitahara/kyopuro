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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
  int n;
  cin >> n;
  V x(n);
  REP(i, n)
  {
    cin >> x[i];
  }

  V p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

  ll ans = 1000000000000000000LL;
  for (int bit = 1; bit < (1 << p.size()); bit++) // 1 << n = 2^n通り.
  {
    ll num = 1;
    for (int i = 0; i < p.size(); i++)
    { // bit桁までi桁を調べる.
      if (bit & (1 << i))
      {
        num *= p[i];
      }
    }
    int flg = 0;
    REP(i, n)
    {
      if (gcd(num, x[i]) != 1)
      {
        flg++;
      }
    }
    if (flg == n)
    {
      ans = min(num, ans);
    }
  }

  cout << ans << endl;
  return 0;
}