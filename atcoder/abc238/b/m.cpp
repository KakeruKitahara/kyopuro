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
  REP(i, n)
  {
    cin >> a[i];
  }

  int o = 0;
  V ans;
  REP(i, n)
  {
    ans.push_back((o + a[i]) % 360);
    o = (o + a[i]) % 360;
  }

  sort(ans.begin(), ans.end());

  int ansi = ans[0];
  REP(i, n)
  {
    ansi = max(ansi, ans[i + 1] - ans[i]);
  }
  ansi = max(ansi, 360 - ans[n - 1]);

  cout << ansi << endl;
  return 0;
}