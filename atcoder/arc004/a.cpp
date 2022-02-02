#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x[100], y[100];
  int n;
  double max = 0;
  double temp;

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &x[i], &y[i]);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      temp = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
      if (max <temp)
        max = temp;
    }
  }
  printf("%f", max);
  return 0;
}