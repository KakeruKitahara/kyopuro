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
  V x(1000);
  V y(1000);
  REP(i, 3)
  {
    int a, b;
    cin >> a >> b;
    x[a + 100]++;
    y[b + 100]++;
  }

  REP(i, x.size())
  {
    if (x[i] == 1)
    {
      cout << i - 100 << " ";
      break;
    }
  }
  REP(i, y.size())
  {
    if (y[i] == 1)
    {
      cout << i - 100;
      break;
    }
  }
  cout << endl;

  return 0;
}