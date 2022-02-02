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
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int x = a[n / 2];

  double y = x / 2.0;

  ll sum = 0;
  int acnt = 0, bcnt = 0;
  REP(i, n)
  {
    sum += a[i];
    sum -= min(a[i], x);
  }

  sum += (ll)n / 2 * x;
  double tmp = 0;
  if (n % 2 != 0)
  {
    tmp = y;
  }

  cout << setprecision(20) << (double)(sum + tmp) / n << endl; //必要.
  return 0;
}