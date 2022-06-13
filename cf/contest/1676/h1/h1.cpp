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
    int cnt = 0;
    REP(j, a[i].size())
    {
      REP2(k, j + 1, a[i].size())
      {
        if (a[i][k] <= a[i][j])
        {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }

  return 0;
}