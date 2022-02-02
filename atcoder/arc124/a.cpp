#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint998244353;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<char> c(k);
  V k2(k);

  REP(i, k)
  {
    cin >> c[i] >> k2[i];
  }

  vector<mint> cnt(n, k);

  REP(i, k)
  {
    if (c[i] == 'L')
    {
      cnt[k2[i] - 1] = 1;
      REP(j, k2[i] - 1)
      {
        if (cnt[j] == 1)
          continue;
        cnt[j]--;
      }
    }

    if (c[i] == 'R')
    {
      cnt[k2[i] - 1] = 1;
      REP2(j, k2[i], n)
      {
        if (cnt[j] == 1)
          continue;
        cnt[j]--;
      }
    }
  }

  mint ans = cnt[0];

  REP(i, n)
  {
    if (i == 0)
      continue;
    ans *= cnt[i];
  }

  cout << ans.val() << endl;

  return 0;
}