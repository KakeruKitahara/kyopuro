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
  fenwick_tree<int> ff[200000];
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  REP(i, n)
  {
    ff[a[i]].add(i + 1, 1);
  }

  int q;
  cin >> q;

  VV qu(q, V(3, 0));
  REP(i, q)
  {
    cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
  }

  REP(i, q)
  {
    cout << ff[qu[i][2]].sum(qu[i][0] - 1, qu[i][1] - 1) << endl;
  }

  return 0;
}