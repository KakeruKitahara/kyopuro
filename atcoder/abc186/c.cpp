#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int k, l, digit = 0;
  int n_10 = n, n_8 = n;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    int flag = 0;
    n_10 = n_8 = i;
    while (n_10 != 0)
    {
      k = n_10 % 10;
      l = n_8 % 8;

      if (k == 7 || l == 7)
      {
        flag = 1;
        break;
      }
      else
      {
        n_10 /= 10;
        n_8 /= 8;
      }
    }
    if (flag == 0)
    {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}