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
/* 
int main()
{
  int a, b, w;
  cin >> a >> b >> w;

  int tmps = w * 1000;
  int mins = 2 * 1000 * 1000;
  int maxs = -1;
  int cnt = 0;

  REP2(i, a, b + 1)
  {
    tmps = w * 1000;
    cnt = 0;
    while (tmps > i)
    {
      tmps -= i;
      cnt++;
    }
    if (a <= tmps)
    {
      cnt++;
      mins = min(cnt, mins);
      maxs = max(cnt, maxs);
    }
    else
    {
      REP2(j, 1, 100)
      {
        if (tmps + j * i <= b)
        {
          cnt -= j - 1;
          mins = min(cnt, mins);
          maxs = max(cnt, maxs);
        }
      }
    }
  }

  if (maxs == -1)
  {
    cout << "UNSATISFIABLE";
  }
  else
  {
    cout << mins << " " << maxs;
  }

  return 0;
}
*/