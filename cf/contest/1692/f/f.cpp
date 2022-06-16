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
  VV a(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    a[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }

  REP(i, t)
  {
    VV d(10);

    REP(j, a[i].size())
    {
      d[a[i][j] % 10].push_back(j);
    }
    int f = 0;
    REP(j, 10)
    {
      REP(k, 10)
      {
        REP(l, 10)
        {
          int b1 = 0, b2 = 0, b3 = 0;
          if (l == j && j == k)
          {
            b1 = 2;
            b2 = 2;
            b3 = 2;
          }
          else if (k == j)
          {
            b1 = 1;
            b2 = 1;
          }
          else if (l == k)
          {
            b2 = 1;
            b3 = 1;
          }
          else if (l == j)
          {
            b1 = 1;
            b3 = 1;
          }
          if (d[j].size() > b1 && d[k].size() > b2 && d[l].size() > b3)
          {
            if ((k + j + l) % 10 == 3 && d[j].size() + d[k].size() + d[l].size() >= 3)
            {
              cout << "YES" << endl;
              f = 1;
            }
            if (f == 1)
              break;
          }
        }
        if (f == 1)
          break;
      }
      if (f == 1)
        break;
    }
    if (f == 1)
      continue;
    cout << "NO" << endl;
  }

  return 0;
}