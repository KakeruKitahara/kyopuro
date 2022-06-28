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
  S k;
  cin >> n >> k;
  ll k3 = stol(k);
  reverse(k.begin(), k.end());
  ll k2 = stol(k);
  if (k[0] == '0')
  {
    k2 = k3;
  }

  if(k3 > k2){
    cout << 0 << endl;
    return 0;
  }

  ll a = k2;
  ll b = k3;

  ll ans = 0;
  REP(i, 20)
  {
    if (k3 <= n)
    {
      ans++;
      k3 *= 10;
    }
    if (k2 <= n)
    {
      ans++;
      k2 *= 10;
    }
  }
  if (a == b)
  {
    cout << ans / 2 << endl;
  }
  else
    cout << ans << endl;

  return 0;
}