#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;

int main()
{
  ll n, k;
  cin >> n >> k;
  pair<ll, ll> f[n + 1];
  REP(i, n)
  {
    cin >> f[i].first >> f[i].second;
  }

  f[n].first = 0;
  f[n].second = 0;

  sort(f, f + n + 1);

  ll sum = 0;
  REP2(i, 1, n + 1)
  {
    if (k - (f[i].first - f[i - 1].first) < 0)
    {
      cout << sum + k << endl;
      return 0;
    }
    else
    {
      k += - (f[i].first - f[i - 1].first);
      k += f[i].second;

      sum += (f[i].first - f[i - 1].first);
    }
  }
  cout << sum  +  k << endl;

  return 0;
}