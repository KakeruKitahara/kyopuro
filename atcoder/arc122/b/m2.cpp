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
  Vl a(n);
  ll sum = 0;
  REP(i, n)
  {
    cin >> a[i];
    sum += a[i];
  }

  ll sumi = 0;

  sort(a.begin(), a.end());

  ll ans = LINF;
  REP(i, n)
  {
    ll k = n * a[i] + 2 * (sum - sumi - (n - i) * a[i]);
    sumi += a[i];
    ans = min(k, ans);
  }

  cout << fixed << setprecision(10) << ans / (2.0 * n) << endl;

  return 0;
}