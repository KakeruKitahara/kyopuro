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
  ll n;
  cin >> n;

  ll sum = 0;
  int cnt;
  REP2(i, 1, IINF)
  {
    sum += i;
    if (sum > 1000000000000LL)
    {
      cnt = i;
      break;
    }
  }

  int ans = 0;

  REP2(j, 1, cnt)
  {
    ll i = j;
    if ((2 * n + i * (1 - i)) >= (2 * i) && (2 * n + i * (1 - i)) % (2 * i) == 0)
    {
      ans++;
    }
  }

  cout << ans * 2 << endl;

  return 0;
}