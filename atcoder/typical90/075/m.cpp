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

vector<pair<ll, ll>> prime_factor(ll n)
{
  vector<pair<ll, ll>> ret;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    ll tmp = 0;
    while (n % i == 0)
    {
      tmp++;
      n /= i;
    }
    ret.push_back(make_pair(i, tmp));
  }
  if (n != 1)
    ret.push_back(make_pair(n, 1));
  return ret;
}

int main()
{
  ll n;
  cin >> n;
  vector<pair<ll, ll>> p = prime_factor(n);

  ll sum = 0;
  REP(i, p.size())
  {
    sum += p[i].second;
  }

  int ans = 0;
  while (sum != 1)
  {
    sum = (sum + 1) / 2;
    ans++;
  }

  cout << ans;

  return 0;
}