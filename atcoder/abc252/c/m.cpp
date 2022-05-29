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
  vector<S> s(n);
  REP(i, n)
  {
    cin >> s[i];
  }

  int ans = IINF;
  REP(i, 10)
  {
    set<int> c;
    REP(j, n)
    {
      REP(k, 10)
      {
        if (i == s[j][k] - '0')
        {
          int ind = k;
          while (c.count(ind) == 1)
          {
            ind += 10;
          }
          c.insert(ind);
        }
      }
    }
    auto mins = c.end();
    mins--;

    ans = min(*mins, ans);
  }

  cout << ans << endl;

  return 0;
}