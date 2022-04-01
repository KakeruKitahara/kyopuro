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
  ll n, m;
  cin >> n >> m;

  Vl a(n + 1), c(n + m + 1);

  REPR(i, n + 1)
  {
    cin >> a[i];
  }
  REPR(i, n + m + 1)
  {
    cin >> c[i];
  }

  Vl b(m + 1);

  ll wa = 0;
  REP(i, m + 1)
  {
    wa = 0;
    int k = i - 1;
    for (int j = 1; j <= i ; j++, k--)
    {
      wa += b[k] * a[j];
    }
    b[i] = (c[i] - wa) / a[0];
  }

  REPR(i, m + 1)
  {
    cout << b[i] << " ";
  }
  cout << endl;

  return 0;
}