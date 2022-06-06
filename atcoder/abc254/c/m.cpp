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
  int n, k;
  cin >> n >> k;

  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  VV p(k);

  REP(i, n)
  {
    p[i % k].push_back(a[i]);
  }

  REP(i, k)
  {
    sort(p[i].begin(), p[i].end());
  }
  V b(n);
  int l = 0, j = 0;
  REP(i, n)
  {
    b[i] = p[l][j];
    if (l == k - 1)
    {
      l = 0;
      j++;
    }
    else
      l++;
  }

  REP(i, n - 1)
  {
    if (b[i] > b[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}