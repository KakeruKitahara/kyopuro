#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int i = 0;
  for (i = 0;; i++)
  {
    if (!(a > i && b > i && c > i && d > i))
    {
      break;
    }
  }
  printf("%d", i);
  return 0;
}