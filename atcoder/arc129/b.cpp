#include <bits/stdc++.h>
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
  V r(n);
  V l(n);
  set<int> sl;
  set<int> sr;

  REP(i, n)
  {
    cin >> l[i];
    cin >> r[i];
  }

  REP(i, n)
  {
    sr.insert(r[i]);
    sl.insert(l[i]);

    int x = (*sr.begin() + *sl.rbegin()) / 2;

    if (max((*sl.rbegin() - x), (x - *sr.begin())) <= 0)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << max((*sl.rbegin() - x), (x - *sr.begin())) << endl;
    }
  }

  return 0;
}