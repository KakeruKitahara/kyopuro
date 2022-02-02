#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)

using VV = vector<vector<int>>;
using S = string;
using ll = long long;
using P = pair<ll, ll>;
using V = vector<ll>;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  ll h, w, c, q;

  cin >> h >> w >> c >> q;

  V t(q), n(q), cc(q);
  int row = 0, col = 0;
  V color(c + 1);
  map<P, P> mp;

  int t1 = 0, t2 = 0;

  REP(i, q)
  {
    cin >> t[i] >> n[i] >> cc[i];
    mp[make_pair(t[i], n[i])] = make_pair(i, cc[i]);
  }

  vector<P> aa;
  vector<pair<int, P>> bb;
  for (auto i = mp.begin(); i != mp.end(); i++)
  {
    bb.push_back(make_pair(i->second.first, i->first));
    aa.push_back(i->second);
  }

  sort(aa.rbegin(), aa.rend());
  sort(bb.rbegin(), bb.rend());

  REP(i, aa.size())
  {
    if (bb[i].second.first == 1)
    {
      color[aa[i].second] += w - col;
      row++;
    }
    else
    {
      color[aa[i].second] += h - row;
      col++;
    }
  }

  REP2(i, 1, c + 1)
  {
    cout << color[i] << " ";
  }

  return 0;
}