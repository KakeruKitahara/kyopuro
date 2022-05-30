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
  int t;
  cin >> t;

  vector<ll> n2(t), n3(t), n4(t);
  REP(i, t)
  {
    cin >> n2[i] >> n3[i] >> n4[i];
  }

  REP(i, t)
  {
    ll ans = 0;
    ll tmp;

    ans += tmp = min(n3[i] / 2, n4[i]);
    n4[i] -= tmp;
    n3[i] -= tmp * 2;

    ans += tmp = min(n3[i] / 2, n2[i] / 2);
    n2[i] -= tmp * 2;
    n3[i] -= tmp * 2;

    ans += tmp = min(n4[i] / 2, n2[i]);
    n4[i] -= tmp * 2;
    n2[i] -= tmp;

    ans += tmp = min(n4[i], n2[i] / 3);
    n4[i] -= tmp;
    n2[i] -= tmp * 3;

    ans += n2[i] / 5;
    cout << ans << endl;
  }

  return 0;
}