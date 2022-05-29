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
  int k;

  cin >> n >> k;
  V b(k);
  vector<P> a(n);
  REP(i, n)
  {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  REP(i, k)
  {
    cin >> b[i];
  }

  sort(a.rbegin(), a.rend());

  REP(i, n)
  {
    REP(j, k)
    {
      if (a[i].second == b[j])
      {
        cout << "Yes" << endl;
        return 0;
      }
    }

    if (a[i].first != a[i + 1].first)
    {
      break;
    }
  }

  cout << "No" << endl;

  return 0;
}