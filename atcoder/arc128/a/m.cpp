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
  int n;

  cin >> n;
  V a(n);
  map<int, int> ind;

  REP(i, n)
  {
    cin >> a[i];
    ind[a[i]] = i;
  }

  int f = 1;
  V ans(n);
  int mins = IINF;
  int maxs = 0;
  int pre = 0;
  int m = n;

  REP(i, n - 1)
  {
    if (a[i] > a[i + 1])
    {
      pre = a[i];
      m = i;
      ans[i] = 1;
      break;
    }
  }
  REP2(i, m + 1, n)
  {
    if (f == 0)
    {
      if (a[i] < pre)
      {
        pre = maxs;
        ans[ind[maxs]] = 1;
        i = ind[maxs];
        f = 1;
        maxs = 0;
      }
      else
      {
        maxs = max(maxs, a[i]);
      }
    }
    else
    {
      if (a[i] > pre)
      {
        pre = mins;
        ans[ind[mins]] = 1;
        i = ind[mins];
        f = 0;
        mins = IINF;
      }
      else
      {
        mins = min(mins, a[i]);
      }
    }
  }

  if (m != n && f == 1)
  {
    ans[ind[mins]] = 1;
  }
  if (m != n && f == 0)
  {
    ans[ind[maxs]] = 1;
  }

  REP(i, n)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}