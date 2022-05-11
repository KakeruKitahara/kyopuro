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
  int n;
  cin >> n;
  VV a(n);
  VV b(n);

  REP(i, n)
  {
    int t;
    cin >> t;
    a[i].resize(t);
    b[i].resize(t);
    REP(j, t)
    {
      cin >> a[i][j];
      b[i][j] = abs(a[i][j]);
    }
  }

  V ans(n);
  V c(n);
  V d(n);

  REP(i, n)
  {
    int f = 0;
    REP(j, a[i].size() - 1)
    {
      if (a[i][j] < 0)
      {
        d[i]++;
      }

      if (b[i][j] < b[i][j + 1])
      {
        if (!f)
        {
          f = 1;
        }
        else if (f == 2)
        {
          c[i] = j;
          f = 4;
        }
        else if (f == 3)
        {
          ans[i] = 1;
          break;
        }
      }

      if (b[i][j] > b[i][j + 1])
      {
        if (!f)
        {
          f = 2;
        }
        else if (f == 1)
        {
          c[i] = j;
          f = 3;
        }
        else if (f == 4)
        {
          ans[i] = 1;
          break;
        }
      }
    }
    if (f == 1)
    {
      c[i] = -1;
    }
    else if (f == 2)
    {
      c[i] = a[i].size() - 1;
    }
    if (a[i].back() < 0)
    {
      d[i]++;
    }
  }

  REP(i, n)
  {
    if (d[i] != c[i] + 1)
    {
      ans[i] = 1;
    }
  }

  REP(i, n)
  {
    if (ans[i])
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0;
}