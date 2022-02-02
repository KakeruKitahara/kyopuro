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

  if (n % 2 == 1)
  {
    return 0;
  }

  for (int bit = 0; bit < (1 << n); bit++) // 1 << n = 2^n通り.
  {
    int cnt = 0;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
      if (bit & (1 << i))
      {
        cnt++;
        value++;
      }
      else
      {
        value--;
      }
      if (value < 0)
      {
        break;
      }
    }
    if (value == 0 && cnt == n / 2)
    {
      REPR(i, n)
      {
        if (bit & (1 << i))
        {
          cout << ")";
        }
        else
        {
          cout << "(";
        }
      }
      cout << "\n";
    }
  }

  return 0;
}