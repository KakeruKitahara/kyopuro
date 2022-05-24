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

uint32_t xor128(void)
{
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y;
  y = z;
  z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main()
{

  int n;
  cin >> n;
  Vl a(n), b(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }
  int q;
  cin >> q;

  vector<P> xy(q);

  REP(i, q)
  {
    cin >> xy[i].first >> xy[i].second;
  }

  set<ll> o;
  REP(i, n)
  {
    o.insert(a[i]);
    o.insert(b[i]);
  }

  map<ll, ll> tra, tra2;

  for (int i : o)
  {
    tra[i] = xor128();
  }

  tra2 = tra;

  REP(i, n)
  {
    int t1 = a[i], t2 = b[i];
    a[i] = tra[a[i]];
    b[i] = tra2[b[i]];
    tra[t1] = -1;
    tra2[t2] = -1;
  }

  Vl suma(n), sumb(n);

  REP(i, n)
  {
    if (i == 0)
    {
      suma[i] = a[i];
      sumb[i] = b[i];
      continue;
    }
    if (a[i] != -1)
      suma[i] = suma[i - 1] ^ a[i];
    else
      suma[i] = suma[i - 1];
    if (b[i] != -1)
      sumb[i] = sumb[i - 1] ^ b[i];
    else
      sumb[i] = sumb[i - 1];
  }

  REP(i, q)
  {
    if (suma[xy[i].first - 1] == sumb[xy[i].second - 1])
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }

  return 0;
}