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
  int n, cnt = 0, flag = 0;
  cin >> n;
  int a[n], b[n];
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }

  REP2(j, a[0], b[0] + 1)
  {
    REP(i, n)
    {
      if (a[i] <= j && j <= b[i])
      {
        flag++;
      }
    }
    if (flag == n)
    {
      cnt++;
    }
    flag = 0;
  }

  cout << cnt << endl;
  return 0;
}