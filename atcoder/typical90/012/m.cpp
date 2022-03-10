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
  int h, w, q;
  cin >> h >> w >> q;
  dsu d(h * w);
  VV mp(h, V(w));
  vector<S> ans;
  P walk[4] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
  REP(i, q)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      mp[r][c] = 1;
      REP(j, 4)
      {
        if (0 <= r + walk[j].first && r + walk[j].first < h && 0 <= c + walk[j].second && c + walk[j].second < w)
        {
          if (mp[r + walk[j].first][c + walk[j].second] == 1)
          {
            d.merge(r * w + c, (r + walk[j].first) * w + c + walk[j].second);
          }
        }
      }
    }
    else if (t == 2)
    {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;
      ca--;
      rb--;
      cb--;
      if (d.same(ra * w + ca, rb * w + cb) && mp[ra][ca] == 1 && mp[rb][cb] == 1)
        ans.push_back("Yes");
      else
        ans.push_back("No");
    }
  }

  REP(i, ans.size())
  {
    cout << ans[i] << endl;
  }

  return 0;
}