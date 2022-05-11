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

  REP(i, n)
  {
    int t;
    cin >> t;
    a[i].resize(t);
    REP(j, t)
    {
      cin >> a[i][j];
    }
  }

  REP(i, n)
  {
    int mins = IINF;

    REP(j, a[i].size())
    {
      mins = min(a[i][j], mins);
    }
    int ans = 0;
    REP(j, a[i].size())
    {
      ans+= a[i][j] - mins;
    }
    cout << ans << endl;
  }

  return 0;
}