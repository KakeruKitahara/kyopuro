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
  int n, k, q;
  cin >> n >> k >> q;
  V a(k);
  V l(q);
  REP(i, k)
  {
    cin >> a[i];
  }
  REP(i, q)
  {
    cin >> l[i];
    l[i]--;
  }

  REP(i, q)
  {
    if (l[i] != k - 1 && a[l[i]] + 1 != a[l[i] + 1])
    {
      a[l[i]]++;
    }
    else if (l[i] == k - 1 && a[l[i]] != n)
    {
      a[l[i]]++;
    }
  }

  REP(i, k)
  {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}