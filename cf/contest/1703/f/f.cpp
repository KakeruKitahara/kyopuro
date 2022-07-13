#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  vector<P> b;
  REP(i, n)
  {
    if (a[i] < i + 1)
    {
      b.push_back(make_pair(a[i], i + 1));
    }
  }
  sort(b.begin(), b.end());

  ll ans = 0;
  REP(i, b.size())
  {
    ans += b.end() - lower_bound(b.begin(), b.end(), make_pair(b[i].second + 1, 0));
  }

  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}