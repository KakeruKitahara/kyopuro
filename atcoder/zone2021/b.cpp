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
  int n, d, h;
  cin >> n >> d >> h;
  int d2[n], h2[n];

  REP(i, n)
  {
    cin >> d2[i] >> h2[i];
  }

  double ans = -1;
  REP(i, n)
  {
    double x = ((double)(d * h2[i] - d2[i] * h) / (d - d2[i]));
    ans = max(x, ans);
  }

  if (ans <= 0)
  {
    ans = 0;
  }
  cout << ans << endl;

  return 0;
}