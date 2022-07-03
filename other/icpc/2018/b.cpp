#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;

void solve(int n, int m, int t, int p)
{
  V d(t), c(t);
  int c1 = 0, c2 = 0;
  REP(i, t)
  {
    cin >> c[i] >> d[i];
    if (c[i] == 1)
    {
      c1 += d[i];
    }
    else
    {
      c2 += d[i];
    }
  }

  V x, y;
  REP(i, p)
  {
    int xx, yy;
    cin >> xx >> yy;
    x.push_back(xx);
    y.push_back(yy);
  }

  VV mas(1000, V(1000, 0));

  REP(i, m)
  {
    REP(j, n)
    {
      mas[i][j] = 1;
    }
  }

  int m2 = m;
  int n2 = n;
  int sum1 = 0, sum2 = 0;

  REP(i, t)
  {
    if (c[i] == 1)
    {
      int cc = 1;
      REP2(di, sum1, sum1 + d[i])
      {

        REP2(dj, sum2, sum2 + m2)
        {
          mas[dj][di + d[i]] += mas[dj][di + d[i] - cc];
        }
        cc += 2;
      }
      n2 = max(d[i], n2 - d[i]);
      sum1 += d[i];
    }
    else
    {
      int cc = 1;
      REP2(di, sum2, sum2 + d[i])
      {

        REP2(dj, sum1, sum1 + n2)
        {
          mas[di + d[i]][dj] += mas[di + d[i] - cc][dj];
        }
        cc += 2;
      }
      m2 = max(d[i], m2 - d[i]);
      sum2 += d[i];
    }
  }
  int cnt = 0;
  REP(i, p)
  {
    cout << mas[c2 + y[i]][c1 + x[i]] << endl;
  }
}

int main()
{
  while (1)
  {
    int n, m, t, p;
    cin >> n >> m >> t >> p;
    if (n == 0 && m == 0 && t == 0 && p == 0)
    {
      break;
    }
    solve(n, m, t, p);
  }

  return 0;
}