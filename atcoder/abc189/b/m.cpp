#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  int v[n], p[n];
  rep(i, n)
  {
    cin >> v[i];
    cin >> p[i];
  }

  int a = x;
  a *= 100;
  int j;
  for (j = 0; j < n; j++)
  {
    a -= v[j] * p[j];
    if (a < 0)
    {
      break;
    }
  }
  if (j == n)
  {
    cout << "-1";
  }
  else
  {
    cout << j + 1;
  }

  return 0;
}