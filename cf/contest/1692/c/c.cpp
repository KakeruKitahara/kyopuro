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
  vector<vector<S>> s(t);
  REP(i, t)
  {
    s[i].resize(8);
    REP(j, 8)
    {
      cin >> s[i][j];
    }
  }

  REP(i, t)
  {

    int prev = -1;
    REP(j, 8)
    {
      int cnt = 0;
      int st;
      REP(k, 8)
      {
        if (s[i][j][k] == '#')
        {
          cnt++;
          st = k;
        }
      }
      if (cnt == 1 && prev == 2)
      {
        cout << j + 1 << " " << st + 1 << endl;
        break;
      }
      prev = cnt;
    }
  }

  return 0;
}