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
using mint = modint1000000007;

int main()
{
  S s;
  int k;
  cin >> s >> k;
  int ans = 0;

  // vectorの要素のデフォルト値は0．
  V dot(s.size() + 2);

  REP2(i, 1, s.size() + 1)
  {
    if (s[i - 1] == '.')
      dot[i] = dot[i - 1] + 1;
    else
      dot[i] = dot[i - 1];
  }
  int l = 0;
  int r = l + 1;
  for (; l < s.size() + 1; l++)
  {
    for (; r < s.size() + 1 && dot[r] - dot[l] <= k; r++)
    {
      ans = max(ans, r - l);
    }
  }

  cout << ans << endl;

  return 0;
}