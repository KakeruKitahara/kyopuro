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

void solve(int h)
{
  VV m(h, V(5));
  REP(i, h)
  {
    REP(j, 5)
    {
      cin >> m[i][j];
    }
  }

  int ans = 0;

  REP(ii, h)
  {
    int f = 0;
    REP(i, h)
    {
      VV n(10, V(5));
      REP(j, 4)
      {
        if (m[i][j] == m[i][j + 1])
        {
          n[m[i][j]][j + 1] = n[m[i][j]][j] + 1;
        }
      }
      int ind = -1;
      REP2(k, 1, 10)
      {
        int tmp = -1;
        REP(l, 5)
        {
          tmp = max(n[k][l], tmp);
        }

        if (tmp >= 2)
        {
          f = 1;
          ind = k;
          ans += ind * (tmp + 1);
          break;
        }
      }

      if (ind != -1)
      {
        REP(j, 1)
        {
          if (m[i][j] == ind && m[i][j + 1] == ind && m[i][j + 2] == ind && m[i][j + 3] == ind && m[i][j + 4] == ind)
          {
            m[i][j] = 0;
            m[i][j + 1] = 0;
            m[i][j + 2] = 0;
            m[i][j + 3] = 0;
            m[i][j + 4] = 0;
          }
        }

        REP(j, 2)
        {
          if (m[i][j] == ind && m[i][j + 1] == ind && m[i][j + 2] == ind && m[i][j + 3] == ind)
          {
            m[i][j] = 0;
            m[i][j + 1] = 0;
            m[i][j + 2] = 0;
            m[i][j + 3] = 0;
          }
        }
        REP(j, 3)
        {
          if (m[i][j] == ind && m[i][j + 1] == ind && m[i][j + 2] == ind)
          {
            m[i][j] = 0;
            m[i][j + 1] = 0;
            m[i][j + 2] = 0;
          }
        }

      }
    }

    REP(jj, h)
    {
      for (int i = h - 1; 0 < i; i--)
      {
        REP(j, 5)
        {
          if (m[i][j] == 0)
          {
            m[i][j] = m[i - 1][j];
            m[i - 1][j] = 0;
          }
        }
      }
    }

    if (f == 0)
    {
      break;
    }
  }

  cout << ans << endl;
}

int main()
{
  while (1)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    solve(a);
  }

  return 0;
}