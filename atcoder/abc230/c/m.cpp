#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (long long i = a; i < n; i++)
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
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;

  pair<ll, ll> k1, k2;

  k1.first = p - a < r - b ? r - b : p - a;
  k1.second = q - a < s - b ? q - a : s - b;

  k2.first = p - a < b - s ? b - s : p - a;
  k2.second = q - a < b - r ? q - a : b - r;

  ll k1ptr = k1.first, k2ptr = k2.first;

  REP2(i, p, q + 1)
  {
    REP2(j, r, s + 1)
    {
      if (a + k1ptr == i && b + k1ptr == j)
      {
        cout << "#";
      }
      else if (a + k2ptr == i && b - k2ptr == j)
      {
        cout << "#";
      }
      else
      {
        cout << ".";
      }
      if (a + k1ptr == i && b + k1ptr == j)
      {
        if (k1ptr <= k1.second)
          k1ptr++;
      }
      if (a + k2ptr == i && b - k2ptr == j)
      {
        if (k2ptr <= k2.second)
          k2ptr++;
      }
    }
    cout << endl;
  }

  return 0;
}