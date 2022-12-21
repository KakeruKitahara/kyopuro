]#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  vector<pair<int, int>> t(n);
  set<pair<int, int>> ans;
  REP(i, n)
  {
    cin >> t[i].first >> t[i].second;
  }

  REP(i, n)
  {
    REP(j, n)
    {
      if (i != j)
      {
        pair<int, int> dist = make_pair(t[i].first - t[j].first, t[i].second - t[j].second);
        pair<int, int> gdist;
        gdist.first = dist.first / __gcd(dist.first < 0 ? -dist.first : dist.first, dist.second < 0 ? -dist.second : dist.second);
        gdist.second = dist.second / __gcd(dist.first < 0 ? -dist.first : dist.first, dist.second < 0 ? -dist.second : dist.second);
        ans.insert(gdist);
      }
    }
  }

  cout << ans.size() << endl;

  return 0;
}