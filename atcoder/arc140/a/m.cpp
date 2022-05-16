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
using VVV = vector<vector<vector<int>>>;
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

  S s;

  cin >> s;

  REP2(l, 1, n + 1)
  {
    VV a(2000, V(26));
    int cnt2;
    if (n % l == 0)
    {
      for (int i = 0; i < l; i++)
      {
        int cnt = 0;
        for (int j = i; j < n; j += l)
        {
          cnt++;
          a[i][s[j] - 'a']++;
        }
        cnt2 = cnt;
      }
      int sum = 0;
      REP(i, l)
      {
        int maxs = -1;
        REP(j, 26)
        {
          maxs = max(maxs, a[i][j]);
        }
        sum += cnt2 - maxs;
      }

      if (sum <= k)
      {
        cout << l << endl;
        return 0;
      }
    }
  }

  cout << n << endl;

  return 0;
}