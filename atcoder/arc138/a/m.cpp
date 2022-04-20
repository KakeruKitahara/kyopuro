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
  int n, k;
  cin >> n >> k;
  V a(k);
  vector<P> b;
  int aa;
  REP(i, k)
  {

    cin >> aa;
    a[k - i - 1] = aa;
  }
  int o = 0;
  REP2(i, k, n)
  {
    int bb;
    cin >> bb;
    b.push_back(make_pair(bb, o));
    o++;
  }

  sort(b.begin(), b.end());

  int ans = IINF;
  REP(i, k)
  {
    auto it = lower_bound(b.begin(), b.end(), make_pair(a[i] + 1, 0));
    REP2(j, it - b.begin(), b.size())
    {
      ans = min(b[j].second + i + 1, ans);
    }
  }
  if (ans == IINF)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}
