#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0)
  {
    while (1)
    {
      a--;
      if(a == 0)break;
      b--;
      if (b == 0)
        break;
    }
  }
  else
  {
    while (1)
    {
      b--;
      if (b == 0)
        break;
      a--;
      if (a == 0)
        break;
    }
  }
  if (a > 0)
  {
    cout << "Takahashi";
  }
  if(b > 0)
  {
    cout << "Aoki";
  }
  return 0;
}