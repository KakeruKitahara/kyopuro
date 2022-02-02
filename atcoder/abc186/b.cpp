#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;

  int a[100][100];
  rep(i, h)
          rep(j, w)
              cin >>a[i][j];

  int min = a[0][0];

  rep(i, h)
      rep(j, w) if (min > a[i][j])
          min = a[i][j];
  int sum = 0;
  rep(i, h)
      rep(j, w)
          sum += a[i][j] - min;

  cout << sum;

  return 0;
}