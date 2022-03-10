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

int main()
{

  int n;
  cin >> n;
  vector<S> s(n);
  V r(6), c(6);
  REP(i, n)
  {
    cin >> s[i];
  }

  REP(i, 6)
  {
    REP(j, 6)
    {
      if (s[i][j] == '#')
      {
        r[i]++;
        c[j]++;
      }
    }
  }
  int na1 = 0, na2 = 0;
  REP(j, 6)
  {
    if (s[j][j] == '#')
      na1++;
    if (s[j][5 - j] == '#')
      na2++;
  }

  REP(i, 6)
  {
    if (c[i] >= 4 || r[i] >= 4 || na2 >= 4 || na1 >= 4)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  REP2(i, 5, n)
  {
    if (i != 5)
    {
      REP(j, 6)
      {
        r[j] = 0;
        c[j] = 0;
      }
      REP(j, 6)
      {
        REP(k, 6)
        {
          if (s[i - 5 + j][k] == '#')
          {
            r[j]++;
            c[k]++;
          }
        }
      }
    }

    REP(i, 6)
    {
      if (c[i] >= 4 || r[i] >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }

    int na111 = 0, na222 = 0;
    REP(l, 6)
    {
      if (s[i - l][5 - l] == '#')
      {
        na111++;
      }
      if (s[i - l][l] == '#')
      {
        na222++;
      }
    }

    if (na111 >= 4 || na222 >= 4)
    {
      cout << "Yes" << endl;
      return 0;
    }

    REP2(j, 6, n)
    {

      REP(d, 6)
      {
        c[d] = c[d + 1];
      }
      c[5] = 0;
      REP(d, 6)
      {
        if (s[i - d][j] == '#')
        {
          c[5]++;
        }
      }

      if (c[5] >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }

      int na11 = 0, na22 = 0;
      REP(l, 6)
      {
        if (s[i - l][j - l] == '#')
        {
          na11++;
        }
        if (s[i - l][j - 5 + l] == '#')
        {
          na22++;
        }
      }

      if (na11 >= 4 || na22 >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }

      REP(l, 6)
      {
        if (s[i - l][j - 6] == '#')
        {
          r[5 - l]--;
        }
        if (s[i - l][j] == '#')
        {
          r[5 - l]++;
        }
        if (r[5 - l] >= 4)
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}