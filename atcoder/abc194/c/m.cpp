
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  ll ans = 0;
  ll sum = a[0];
  REP2(j, 1, n)
  {
    ans += (-a[j] * 2 * sum);
    sum += a[j];
  }

  REP(i, n)
  {
    ll tmp = a[i];
    tmp *= a[i];
    tmp *= n - 1;
    ans += tmp;
  }

  cout << ans << endl;

  return 0;
}
