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
  int n, q;
  cin >> n;
  vector<P> a(n);
  REP(i, n)
  {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  cin >> q;

  VV qu(q, V(3));

  REP(i, q)
  {
    int x, l, r;
    cin >> l >> r >> x;
    qu[i][0] = x;
    qu[i][1] = l - 1;
    qu[i][2] = r - 1;
  }

  REP(i, q)
  {
    auto it = lower_bound(a.begin(), a.end(), make_pair(qu[i][0], -IINF));
    auto it2 = upper_bound(a.begin(), a.end(), make_pair(qu[i][0], IINF));

    auto ansit = upper_bound(it, it2, make_pair(qu[i][0], qu[i][1] - 1));
    auto ansit2 = upper_bound(it, it2, make_pair(qu[i][0], qu[i][2]));
    ansit2--;
    cout << ansit2 - ansit + 1 << endl;
  }

  return 0;
}