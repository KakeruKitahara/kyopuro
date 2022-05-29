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
  VV p(t);

  REP(i, t)
  {
    int n;
    cin >> n;
    p[i].resize(n);
    REP(j, n)
    {
      cin >> p[i][j];
    }
  }

  REP(i, t)
  {
    V b;
    REP(j, p[i].size())
    {
      if (j != p[i][j])
      {
        b.push_back(p[i][j]);
      }
    }
    int ans = b[0] & b[1];
    REP2(j, 2, b.size())
    {
      ans &= b[j];
    }
    cout << ans << endl;
  }

  return 0;
}