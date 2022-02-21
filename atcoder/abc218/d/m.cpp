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
  vector<P> xy(n);
  REP(i, n)
  {
    cin >> xy[i].first >> xy[i].second;
  }

  vector<VV> p(n, VV(2));

  map<P, int> mp;
  REP(i, n)
  {
    mp[make_pair(xy[i].first, xy[i].second)] = 1;
  }

  REP(i, n)
  {
    REP(j, n)
    {
      if (i == j)
        continue;
      if (xy[i].first == xy[j].first)
      {
        p[i][0].push_back(j);
      }
      if (xy[i].second == xy[j].second)
      {
        p[i][1].push_back(j);
      }
    }
  }

  ll ans = 0;
  REP(i, n)
  {
    REP(j, p[i][1].size())
    {
      REP(k, p[i][0].size())
      {
        if (mp.count(make_pair(xy[p[i][1][j]].first, xy[p[i][0][k]].second)) == 1)
        {
          ans++;
        }
      }
    }
  }
  cout << ans / 4 << endl;

  return 0;
}