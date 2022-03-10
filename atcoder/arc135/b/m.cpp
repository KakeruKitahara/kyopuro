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
  int n;
  cin >> n;
  V s(n);
  REP(i, n)
  {
    cin >> s[i];
  }

  Vl x(3);
  int f = 0;
  REP(i, 3)
  {
    ll sum = 0;
    ll maxs = -IINF;
    for (int j = i + 1; j < n; j += 3)
    {
      sum += s[j - 1] - s[j];
      maxs = max(maxs, sum);
    }
    if (f == 1)
    {
      cout << "No" << endl;
      return 0;
    }
    x[i] = maxs;
  }

  if (s[0] < x[0] + x[1] + x[2])
  {
    cout << "No" << endl;
    return 0;
  }
  else
  {
    if (!(x[0] == -IINF || x[1] == -IINF || x[2] == -IINF))
    {
      x[0] += s[0] - (x[0] + x[1] + x[2]);
    }
  }

  cout << "Yes" << endl;
  Vl a(n + 2);
  a[0] = max(x[0], 0LL);
  a[1] = max(x[1], 0LL);
  a[2] = max(x[2], 0LL);
  REP(i, 3)
  {
    for (int j = i + 3; j < n + 2; j += 3)
    {
      a[j] = x[i] + s[j - 2] - s[j - 3];
      x[i] = a[j];
    }
  }

  REP(i, n + 2)
  {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}