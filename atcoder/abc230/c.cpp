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

ll max(ll a, ll b)
{
  return a < b ? b : a;
}

ll min(ll a, ll b)
{
  return a > b ? b : a;
}

int main()
{
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;

  pair<ll, ll> k1, k2, k11, k22;

  k1.first = max(1LL - a, 1LL - b);
  k1.second = min(n - a, n - b);

  k2.first = max(1LL - a, b - n);
  k2.second = min(n - a, b - 1LL);

  ll kp1 = k1.first, kp2 = k2.first;

  // xとy
  k11.first = kp1 + a;
  k11.second = kp1 + b;
  k22.first = kp2 + a;
  k22.second = b - kp2;

  if (k11.first < p)
  {
    kp1 = p - a;
    k11.first = kp1 + a;
    k11.second = kp1 + b;
  }
  if (k11.second < r)
  {
    kp1 = r - b;
    k11.first = kp1 + a;
    k11.second = kp1 + b;
  }

  if (k22.first < p)
  {
    kp2 = p - a;
    k22.first = kp2 + a;
    k22.second = b - kp2;
  }
  if (k22.second < r)
  {
    kp2 = b - r;
    k22.first = kp2 + a;
    k22.second = b - kp2;
  }

  for (ll i = p; i <= q; i++)
  {
    for (ll j = r; j <= s; j++)
    {
      if (k22.first == i && k22.second == j && k11.first == i && k11.second == j)
      {
        cout << "#";
        if (kp1 <= k1.second)
        {
          kp1++;
          k11.first = kp1 + a;
          k11.second = kp1 + b;
        }
        if (kp2 <= k2.second)
        {
          kp2++;
          k22.first = kp2 + a;
          k22.second = b - kp2;
        }
      }
      else if (k11.first == i && k11.second == j)
      {
        cout << "#";
        if (kp1 <= k1.second)
        {
          kp1++;
          k11.first = kp1 + a;
          k11.second = kp1 + b;
        }
      }
      else if (k22.first == i && k22.second == j)
      {
        cout << "#";
        if (kp2 <= k2.second)
        {
          kp2++;
          k22.first = kp2 + a;
          k22.second = b - kp2;
        }
      }
      else
      {
        cout << ".";
      }
    }
    cout << "\n";
  }
  cout << endl;

  return 0;
}


