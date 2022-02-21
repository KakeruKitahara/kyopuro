#include <bits/stdc++.h>
using namespace std;
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

int main()
{

  int n;
  cin >> n;
  V a(n), b(n), c(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }
  REP(i, n)
  {
    cin >> c[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;

  REP(i, n)
  {
    auto bp = upper_bound(b.begin(), b.end(), a[i]);
    if (bp == b.end())
    {
      break;
    }
    // ここで消してしまうとずれてしまう．
    auto cp = upper_bound(c.begin(), c.end(), *bp);
    if (cp == c.end())
    {
      break;
    }
    else
    {
      b.erase(bp);
      c.erase(cp);
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}