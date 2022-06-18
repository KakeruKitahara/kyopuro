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
  int n;
  cin >> n;
  V a(n), b(n);
  mint ans = 0;

  REP(i, n)
  {
    cin >> a[i];
  }

  REP(i, n)
  {
    cin >> b[i];
  }

  V rs(3001);

  REP2(i, 1, 3001)
  {
    rs[i] = rs[i - 1] + i;
  }


  REPR(i, n){
    
  }

  return 0;
}