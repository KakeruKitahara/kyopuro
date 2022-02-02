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
  V a(n), b(n);

  REP(i, n)
  {
    cin >> a[i];
  }

  REP(i, n)
  {
    cin >> b[i];
  }

  V x(n);
  set<int> ans;
  REP(i, n)
  {
    x[i] = (a[0] ^ b[i]);
  }

  sort(b.begin(), b.end());

  REP(i, n)
  {
    V c(n);
    REP(j, n)
    {
      c[j] = (a[j] ^ x[i]);
    }

    sort(c.begin(), c.end());
    if (c == b)
    {
      ans.insert(x[i]);
    }
  }

  cout << ans.size() << endl;
  for (int x : ans)
  {
    cout << x << endl;
  }
  return 0;
}