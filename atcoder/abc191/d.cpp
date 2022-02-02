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
  double r;
  pair<double, double> c;
  long long int cnt = 0;

  cin >> c.first >> c.second >> r;

  REP2(i, c.first - r - 1, c.first + r + 1)
  {
    int d = -sqrt((i - r) * (i - r)) - 1;
    int d2 = sqrt((i - r) * (i - r)) + 1;
    for (int j = d; j <= d2; j++)
    {
      if ((c.first - i) * (c.first - i) + (c.second - j) * (c.second - j) <= r)
      {
        cnt++;
      }
    }
  }

  cout << cnt;
  return 0;
}