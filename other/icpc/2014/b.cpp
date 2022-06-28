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

void solve(int r, int n)
{
  V x(n), y(n), h(n);

  map<int, int> w;
  REP(i, n)
  {
    cin >> x[i] >> y[i] >> h[i];
  }

  map<int, double> mp;

  REP2(i, -r * 2, 2 * r + 1)
  {
    mp[i] = -cos(atan((double)r / abs(i / 2.0)));
  }

  REP(i, 21)
  {
    REP2(j, -r * 2, 2 * r + 1)
    {
      if (x[i] < j / 2.0 && j/ 2.0 < y[i])
      {
        if (h[i] < i + mp[i])
        {
          cout << mp[j / 2] << endl;
        }
      }
    }
  }
}

int main()
{
  while (1)
  {
    int r, n;
    cin >> r >> n;
    if (r == 0 && n == 0)
    {
      break;
    }
    solve(r, n);
  }

  return 0;
}