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
  V b(2 * n + 2);
  while (1)
  {
    int f = 0;
    REP2(i, 1, 2 * n + 2)
    {
      if (b[i] == 0)
      {
        cout << i << endl;
        b[i] = 1;
        break;
      }
    }
    int k;
    cin >> k;
    if(k == 0){
      return 0;
    }
    b[k] = 1;
  }
  return 0;
}