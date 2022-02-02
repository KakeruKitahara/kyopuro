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

vector<pair<long long, long long>> prime_factorize(long long N)
{
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; ++a)
  {
    if (N % a != 0)
      continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0)
    {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }
  if (N != 1)
    res.push_back({N, 1});
  return res;
}

int main()
{
  ll k;
  cin >> k;

  vector<pair<ll, ll>> f = prime_factorize(k);

  ll num = 0;
  REP(i, f.size())
  {
    num += f[i].second;
  }

  ll ans = 1;
  REP2(i, num + 1, num + f.size())
  {
    ans *= i;
  }

  int j = 1;
  REP2(i, num + 1, num + f.size())
  {
    ans /= j;
    j++;
  }

  cout << ans << endl;

  return 0;
}