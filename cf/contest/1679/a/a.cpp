#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;

int main()
{
  int t;
  cin >> t;
  Vl n(t);
  REP(i, t)
  {
    cin >> n[i];
  }

  REP(i, t)
  {
    if (n[i] % 2 != 0)
    {
      cout << -1 << endl;
      continue;
    }
    n[i] /= 2;

    ll mins = -1, maxs = -1;
    if (n[i] >= 2)
    {
      maxs = n[i] / 2;
    }

    if (n[i] >= 3)
    {
      if (n[i] % 3 == 1)
      {
        mins = n[i] / 3 + 1;
      }
      else if (n[i] % 3 == 0)
      {
        mins = n[i] / 3;
      }
      else
      {
        mins = n[i] / 3 + 1;
      }
    }

    if (maxs == -1 && mins == -1)
    {
      cout << -1 << endl;
    }
    else if (maxs == -1)
    {
      cout << mins << " " << mins << endl;
    }
    else if (mins == -1)
    {
      cout << maxs << " " << maxs << endl;
    }
    else
    {
      cout << mins << " " << maxs << endl;
    }
  }

  return 0;
}