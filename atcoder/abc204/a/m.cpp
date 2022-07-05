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
  int x, y;
  cin >> x >> y;
  if (x == y)
  {
    cout << x;
    return 0;
  }
  else
  {
    if ((x == 0 && y == 1) || (x == 1 && y == 0))
    {
      cout << 2;
    }
    if ((x == 0 && y == 2) || (x == 2 && y == 0))
    {
      cout << 1;
    }
    if ((x == 1 && y == 2) || (x == 2 && y == 1))
    {
      cout << 0;
    }
  }
  return 0;
}