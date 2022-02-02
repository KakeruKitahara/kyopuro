#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main()
{
  int k;
  cin >> k;

  int ans = 0;
  for (int a = 1; a <= k; a++)
  {
    for (int b = 1; b <= k / a; b++)
    {
      ans += k / a / b;
    }
  }

  cout << ans << endl;
  return 0;
}
