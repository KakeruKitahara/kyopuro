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
  int p;
  V a(10);
  a[0] = 1;
  REP2(i, 1, 10)
  {
    a[i] = a[i - 1] * (i + 1);
  }
  cin >> p;

  int cnt = 0;
  REPR(i, 10)
  {
    while (p >= a[i])
    {
      p -= a[i];
      cnt++;
    }
    if (p == 0)
    {
      cout << cnt << endl;
      return 0;
    }
  }
  return 0;
}