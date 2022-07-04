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
  int n, d;
  cin >> n >> d;
  V l(n), r(n);
  map<int, int> mp;
  REP(i, n)
  {
    cin >> l[i] >> r[i];
  }

  REP(i, n)
  {
    if (mp[l[i] -1] == 2)
      mp[l[i] - 1] = 3;
    else
      mp[l[i] - 1] = 1;

    if (mp[r[i] + d - 1] == 1)
      mp[r[i] + d - 1] = 3;
    else
      mp[r[i] + d - 1] = 2;
  }

  int ans = 0;

  int pre = -1;
  int f = 0;
  for (P k : mp)
  {
    if (k.second == 3)
    {
    }
    else if (pre == 1 && k.second == 2)
    {
      ans++;
      f = 1;
      pre = k.second;
    }
    else
    {
      pre = k.second;
    }
  }

  cout << ans << endl;

  return 0;
}