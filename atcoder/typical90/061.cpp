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
  int q;
  cin >> q;
  V t(q), x(q);
  for (int i = 0; i < q; i++)
  {
    cin >> t[i] >> x[i];
  }
  deque<int> a;

  REP(i, q)
  {
    if (t[i] == 1)
    {
      a.push_front(x[i]);
    }
    else if (t[i] == 2)
    {
      a.push_back(x[i]);
    }
    else
    {
      cout << a[x[i] - 1] << endl;
    }
  }
  return 0;
}