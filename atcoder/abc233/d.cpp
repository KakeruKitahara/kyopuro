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

int main()
{

  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  vector<ll> sum(n + 1);
  map<ll, ll> mp;

  REP2(i, 1, n + 1)
  {
    sum[i] = sum[i - 1] + a[i - 1];
  }

  ll ans = 0;
  REP(i, n + 1)
  {
    // 一緒にmpカウントすることで1 <= l <= r を満たしている．
    mp[sum[i - 1]]++;
    ans += mp[sum[i] - k];
  }

  cout << ans << endl;

  return 0;
}