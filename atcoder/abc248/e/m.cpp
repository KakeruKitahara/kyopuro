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
  int n, k;
  cin >> n >> k;
  V x(n), y(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }
  if (k == 1)
  {
    cout << "Infinity" << endl;
    return 0;
  }
  int ans = 0;

  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      int cnt = 0;
      REP(l, n)
      {
        if (i == l || j == l){
          if(i == l && k == 2){
            ans++;
          }
          continue;
        }
        if (min(x[i], x[j]) <= x[l] && x[l] <= max(x[i], x[j]))
        {
          if (min(y[i], y[j]) <= y[l] && y[l] <= max(y[i], y[j]))
          {
            if ((x[i] - x[l]) * (y[l] - y[j]) == (x[l] - x[j]) * (y[i] - y[l]))
            {
              cnt++;
            }
          }
        }
      }
      if(k == cnt){
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}