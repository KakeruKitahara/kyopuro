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
  S s;
  cin >> s;

  VV alp(26);
  REP(i, n)
  {
    int p = s[i] - 'a';
    alp[p].push_back(i);
  }
  S ans;
  int p = 0;
  REP(i, k)
  {
    REP(j, 26)
    {
      auto it = lower_bound(alp[j].begin(), alp[j].end(), p);
      if (alp[j].size() >= 1 && *it <= n - (k - i) && it != alp[j].end())
      {
        p = *it + 1;
        ans.push_back('a' + j);
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}