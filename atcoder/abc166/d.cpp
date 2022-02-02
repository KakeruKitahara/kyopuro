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
  int x;
  cin >> x;
  ll a, b;
  int flag = 0;
  for (a = -1000; a < 1000; a++) // 見積もりを立てる.
  {

    for (b = -1000; b < 1000; b++)
    {
      if (a * a * a * a * a - b * b * b * b * b == x)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
    {
      break;
    }
  }
  cout << a << " " << b;
  return 0;
}