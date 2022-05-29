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
  ll n, k;
  cin >> n >> k;

  if (k < min(3ll, n))
  {
    
    cout << "0" << endl;
    return 0;
  }

  mint ans = 1;

  REP(i, min(3ll, n))
  {
    ans *= k - i;
  }

  if (n > 3)
  {
    mint kk = k - 2;
    ans *= kk.pow(n - 3);
  }
  cout << ans.val() << endl;

  return 0;
}