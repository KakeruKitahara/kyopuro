#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;

int main()
{
  vector<ll> a(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  if (a[2] - a[1] == a[1] - a[0])
  {
    cout << 0 << endl;
    return 0;
  }
  ll sum = a[0] + a[1] + a[2];

  ll b = sum / 3;
  if (a[1] - b <= 0)
  {
    b = (sum + 2) / 3;
  }

  ll n1 = (a[0] + a[2] - 2LL * b) / 2LL;
  n1 *= 3;

  if (sum % 3 == 1)
  {
    n1 += 2;
  }
  else if (sum % 3 == 2)
  {
    n1 += 1;
  }
  else
  {
    n1 += 3;
  }

  ll n2 = a[1] - b;
  n2 *= 3;

  if (sum % 3 == 1)
  {
    n2 -= 1;
  }
  else if (sum % 3 == 2)
  {
    n2 -= 2;
  }
  cout << max(n1, n2) << endl;

  return 0;
}