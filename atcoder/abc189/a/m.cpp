#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  char a[3];
  rep(i, 3)
  {
    cin >> a[i];
  }
  if (a[0] == a[1] && a[1] == a[2])
  {
    cout << "Won";
  }
  else
  {
    cout << "Lost";
  }
  return 0;
}