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

  int n;
  cin >> n;
  VV a(n, V(6));
  mint ans = 0;

  REP(i, n)
  {
    REP(j, 6)
    {
      cin >> a[i][j];
    }
  }

  REP(i, 6)
  {
    ans += a[0][i];
  }

  REP2(i, 1, n)
  {
    mint sum = 0;
    REP(j, 6)
    {
      sum += ans * a[i][j];
    }
    ans = sum;
  }

  cout << ans.val() << endl;

  return 0;
}