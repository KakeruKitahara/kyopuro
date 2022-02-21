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
  int a, b;
  cin >> a >> b;

  int sum = 0;
  if (a > b)
  {
    REP2(i, 1, a + 1)
    {
      cout << i << " ";
      sum += i;
    }

    REP(i, b - 1)
    {
      cout << -(b - i) << " ";
      sum -= b - i;
    }
  }
  else{
    REP2(i, 1, b + 1)
    {
      cout << -i << " ";
      sum -= i;
    }

    REP(i, a - 1)
    {
      cout << a - i << " ";
      sum += a - i;
    }
  }

  if (sum != 0)
    cout << -sum << endl;
  return 0;
}