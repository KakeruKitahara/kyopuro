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
  ll a[n];
  REP(i, n)
  {
    cin >> a[i];
  }

  REP(i, n)
  {
    a[i] *= 5;
  }

  vector<long long> b(1000, 0);
  REP(i, n)
  {
    ll tmp = a[i] % 1000;
    b[tmp]++;
  }

  ll ans = 0;
  REP(j, b.size())
  {
    ans += (b[j] * (b[j] - 1)) / 2;
  }

  cout << ans << endl;
  return 0;
}