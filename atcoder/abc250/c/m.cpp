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
  int n, q;
  cin >> n >> q;
  V x(q);

  REP(i, q)
  {
    cin >> x[i];
  }

  map<int, int> a2;
  V a(n);

  REP(i, n)
  {
    a2[i + 1] = i;
    a[i] = i + 1;
  }

  REP(i, q)
  {
    int vr, kr;
    if (a2[x[i]] + 1 > n - 1)
    {
      vr = a[a2[x[i]] - 1];
    }
    else
    {
      vr = a[a2[x[i]] + 1];
    }
    int vl = a[a2[x[i]]];
    int kl = a2[x[i]];
    if (a2[x[i]] + 1 > n - 1)
    {
      kr = a2[x[i]] - 1;
    }
    else
    {
      kr = a2[x[i]] + 1;
    }
    swap(a[kl], a[kr]);
    a2[a[kl]] = kl;
    a2[a[kr]] = kr;
  }

  REP(i, n)
  {
    cout << a[i]  << " ";
  }
  cout << endl;

  return 0;
}