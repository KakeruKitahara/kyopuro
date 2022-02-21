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
  int n, p, q;
  cin >> n >> p >> q;

  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  ll ans = 0;

  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      REP2(k, j + 1, n)
      {
        REP2(l, k + 1, n)
        {
          REP2(m, l + 1, n)
          {
            if ((a[i] % p * a[j] % p * a[k] % p * a[l] % p * a[m] % p) % p == q)
            {
              ans++;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}