=#include <bits/stdc++.h>
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

  V l(n);
  set<V> a;
  REP(i, n)
  {
    cin >> l[i];
    V b(l[i]);
    REP(j, l[i])
    {
      cin >> b[j];
    }
    a.insert(b);
  }

  cout << a.size() << endl;

  return 0;
}