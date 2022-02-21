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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int h, w;
  cin >> h >> w;
  VV p(h, V(w, 0));

  REP(i, h)
  {
    REP(j, w)
    {
      cin >> p[i][j];
    }
  }

  int maxs = -1;
  for (int bit = 0; bit < (1 << h); bit++) // 1 << n = 2^n通り.
  {
    V vec(h * w + 1, 0);
    V in, r;
    for (int i = 0; i < h; i++)
    { // bit桁までi桁を調べる.
      if (bit & (1 << i))
      {
        in.push_back(i);
      }
    }

    REP(j, w)
    {
      set<int> a;
      REP(k, in.size())
      {
        a.insert(p[in[k]][j]);
      }
      if (a.size() == 1)
      {
        r.push_back(p[in[0]][j]);
      }
    }

    REP(j, r.size())
    {
      vec[r[j]] += in.size();
      maxs = max(maxs, vec[r[j]]);
    }
  }

  cout << maxs << endl;

  return 0;
}