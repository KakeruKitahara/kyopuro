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
  vector<double> l(n), r(n);
  REP(i, n)
  {
    int t;
    cin >> t >> l[i] >> r[i];
    if (t == 2)
      r[i]-=0.5;
    else if (t == 3)
      l[i]+=0.5;
    else if (t == 4)
    {
      r[i]-=0.5;
      l[i]+=0.5;
    }
  }
  int ans = 0;
  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      if (!(r[i] < l[j] || r[j] < l[i]))
      {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}