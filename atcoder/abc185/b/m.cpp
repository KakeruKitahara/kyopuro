#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);
  int a[m], b[m];
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d", &a[i], &b[i]);
  }
  int re = n;
  int i, j = 0;
  for (i = 1; i <= t; i++)
  {
    if (i <= a[j])
    {
      re--;
    }
    else if (i <= b[j])
    {
      if (re != n)
      {
        re++;
      }
    }
    else
    {
      j++;
      re--;
    }
    if (re <= 0)
    {
      i--;
      break;
    }
  }

  if ((i - 1) == t)
  {
    printf("Yes");
  }
  else
  {
    printf("No");
  }

  return 0;
}