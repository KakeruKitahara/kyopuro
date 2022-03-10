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
  int n, l, k;
  cin >> n >> l >> k;
  V a(n + 2);
  a[0] = 0;
  REP2(i, 1, n + 1)
  {
    cin >> a[i];
  }
  a[n + 1] = l;

  int r = l;
  int ll = 1;
  int c;

  while (1)
  {
    c = (r + ll) / 2;
    if(c == r || c == ll){ // 最小化の最大化の際はcとr，lが隣り合わせ（最後）になるまで2分探索．
      break;
    }
    int k2 = 0;
    int j = 0;
    REP2(i, 1, n + 2)
    {
      if (a[i] - a[j] >= c)
      {
        k2++;
        j = i;
      }
    }
    if (k2 < k + 1)
    {
      r = c;
    }
    else
    {
      ll = c;
    }
  }

  cout << c << endl;

  return 0;
}