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
/*WA*/

int main()
{
  int n, m;
  cin >> n >> m;
  V s(n - 1);
  V x(m);
  REP(i, n - 1)
  {
    cin >> s[i];
  }
  REP(i, m)
  {
    cin >> x[i];
  }

  map<int, ll> cnt;
  V ao(n);
  V ae(n);
  REP2(i, 1, n)
  {
    if (i % 2 == 0)
      ae[i] = s[i - 1] - ao[i - 1];
    else
      ao[i] = s[i - 1] - ae[i - 1];
  }

  map<int, int> cnto;
  map<int, int> cnte;

  REP2(i, 1, n)
  {
    if (i % 2 == 0)
      cnte[ae[i]]++;
    else
      cnto[ao[i]]++;
  }

  V eo;
  V ee;

  for (P c : cnto)
  {
    eo.push_back(c.second);
  }

  for (P k : cnte)
  {
    ee.push_back(k.second);
  }

  sort(ee.rbegin(), ee.rend());
  sort(eo.rbegin(), eo.rend());
  V max;
  REP(j, m)
  {
    if (eo.size() > j)
      max.push_back(eo[j]);
    if (ee.size() > j)
      max.push_back(ee[j]);
  }
  sort(max.rbegin(), max.rend());

  ll ans = 0;
  REP(i, m)
  {
    ans += max[i];
  }

  cout << ans << endl;

  return 0;
}