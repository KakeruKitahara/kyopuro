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
using mint = modint998244353;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  mint ans = 0;

  vector<vector<mint>> cb(2500, vector<mint>(2500, 0));
  for (int j = 0; j < 2500; j++)
    cb[j][0] = 1;
  for (int i = 1; i < 2500; i++)
  {
    for (int j = 1; j < 2500; j++)
    {
      cb[i][j] = cb[i - 1][j - 1] + cb[i - 1][j];
    }
  }

  REP2(i, n, k + 1)
  {
    int a = i - 1;
    int b = n - 1;
    ans += cb[a][b];
  }

  cout << ans.val() << endl;

  return 0;
}