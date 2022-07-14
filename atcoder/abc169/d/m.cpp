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
  // {{first, second}, {2, n_1}, {3, n_2}, {5, n_3}}のような配列を返す．
  vector<pair<long long, long long>> prime;
  for (long long ind = 2; ind * ind <= n; ind++)
  {
    if (n % ind != 0)
      continue;
    long long ex = 0;
    while (n % ind == 0)
    {
      ex++;
      n /= ind;
    }
    prime.push_back({ind, ex});
  }

  if (n != 1)
    prime.push_back({n, 1});

  ll ans = 0;

  REP(i, prime.size())
  {
    int cnt = 1;
    REP2(j, 1, 10)
    {
      if (cnt > prime[i].second)
      {
        ans += j - 1;
        break;
      }
      cnt += j + 1;
    }
  }

  cout << ans << endl;

  return 0;
}