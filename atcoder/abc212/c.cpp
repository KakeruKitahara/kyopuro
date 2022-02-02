#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  sort(a.begin(), a.end());

  sort(b.begin(), b.end());
  int ans = INF;
  REP(i, n)
  {
    auto minb = lower_bound(b.begin(), b.end(), a[i]);
    if (minb == b.end())
    {
      ans = min(ans, abs(a[i] - *(b.end() - 1)));
    }
    else
    {
      ans = min(ans, abs(a[i] - *minb));
    }
    if (minb != b.begin())
    {
      ans = min(ans, abs(a[i] - *(minb - 1)));
    }
  }

  cout << ans << endl;

  return 0;
}