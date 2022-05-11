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
  vector<S> s(t);

  REP(i, t)
  {
    int b;
    cin >> b;
    cin >> s[i];
  }

  REP(i, t)
  {
    int r = 0, b = 0, f = 1;
    REP(j, s[i].size())
    {
      if (s[i][j] == 'W')
      {
        if (b == 0 && r != 0 || b != 0 && r == 0)
        {
          f = 0;
        }
        b = 0;
        r = 0;
      }
      else if (s[i][j] == 'B')
      {
        b++;
      }
      else
      {
        r++;
      }
    }
    if (b == 0 && r != 0 || b != 0 && r == 0)
    {
      f = 0;
    }
    if (f)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}