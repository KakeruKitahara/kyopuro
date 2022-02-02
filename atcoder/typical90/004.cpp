#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using LL = long long;

int main()
{
  int h, w;
  cin >> h >> w;
  int a[h][w];
  REP(i, h)
  {
    REP(j, w)
    {
      cin >> a[i][j];
    }
  }
  int sumR[h], sumL[w];
  REP(i, h)
  {
    sumR[i] = accumulate(a[i], a[i] + w, 0);
  }
  REP(i, w)
  {
    int tmp = 0;
    REP(j, h)
    {
      tmp += a[j][i];
    }
    sumL[i] = tmp;
  }

  int b[h][w];
  REP(i, h)
  {
    REP(j, w)
    {
      b[i][j] = sumR[i] + sumL[j] - a[i][j];
    }
  }
  REP(i, h)
  {
    REP(j, w)
    {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}