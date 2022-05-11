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
  vector<vector<S>> s(n);

  REP(i, n)
  {
    int t, k;
    cin >> t >> k;
    s[i].resize(t);
    REP(j, t)
    {
      cin >> s[i][j];
    }
  }

  REP(i, n)
  {
    int mins = IINF;
    REP(j, s[i].size())
    {
      REP2(l, j + 1, s[i].size())
      {
        int co = 0;
        REP(k, s[i][j].size())
        {
          char c1 = s[i][j][k];
          char c2 = s[i][l][k];
          co += abs(c1 - c2);
        }
        mins = min(co, mins);
      }
    }
    cout << mins << endl;
  }

  return 0;
}