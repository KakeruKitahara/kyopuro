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
  int n, m;
  cin >> n >> m;
  vector<S> s(n);
  REP(i, n)
  {
    cin >> s[i];
  }

  V r, c;
  REP(i, n)
  {
    int cnt = 0;
    REP(j, m)
    {
      if (s[i][j] == '.')
      {
        cnt++;
      }
    }
    if (cnt == m)
    {
      r.push_back(i);
    }
  }

  REP(i, m)
  {
    int cnt = 0;
    REP(j, n)
    {
      if (s[j][i] == '.')
      {
        cnt++;
      }
    }
    if (cnt == n)
    {
      c.push_back(i);
    }
  }

  REP(i, n)
  {
    int mo = 0;
    REP(j, m)
    {
      int f = 0;
      REP(k, r.size())
      {
        if (r[k] == i)
        {
          f = 1;
        }
      }
      REP(k, c.size())
      {
        if (c[k] == j)
        {
          f = 1;
        }
      }

      if (f == 1)
        continue;

      cout << s[i][j];
      mo++;
    }
    if (mo > 0)
    {
      cout << endl;
    }
  }

  return 0;
}