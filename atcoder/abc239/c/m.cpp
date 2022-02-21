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
  vector<P> xy(2);
  cin >> xy[0].first >> xy[0].second;
  cin >> xy[1].first >> xy[1].second;

  vector<vector<P>> v(2);
  REP(i, 2)
  {
    v[i].push_back(make_pair(xy[i].first + 1, xy[i].second + 2));
    v[i].push_back(make_pair(xy[i].first + 2, xy[i].second + 1));
    v[i].push_back(make_pair(xy[i].first + 2, xy[i].second - 1));
    v[i].push_back(make_pair(xy[i].first + 1, xy[i].second - 2));
    v[i].push_back(make_pair(xy[i].first - 1, xy[i].second - 2));
    v[i].push_back(make_pair(xy[i].first - 2, xy[i].second - 1));
    v[i].push_back(make_pair(xy[i].first - 2, xy[i].second + 1));
    v[i].push_back(make_pair(xy[i].first - 1, xy[i].second + 2));
  }

  REP(i, 8)
  {
    REP(j, 8)
    {
      if (v[0][i] == v[1][j])
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}