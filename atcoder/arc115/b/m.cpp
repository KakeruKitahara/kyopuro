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

/* 誤答
int main()
{
  int n;
  cin >> n;
  VV c(n, V(n));

  REP(i, n)
  {
    REP(j, n)
    {
      cin >> c[i][j];
    }
  }

  ll maxs = -1;
  int ind = -1;
  V a(n), b(n);

  REP(i, n)
  {
    if (maxs < c[i][0] - c[(i + 1) % n][0])
    {
      ind = i;
      maxs = c[i][0] - c[(i + 1) % n][0];
    }
  }

  if (ind == -1)
  {
    cout << "No" << endl;
    return 0;
  }

  a[ind] = maxs;
  cout << ind << endl;

  int j = ind + 1;
  if (2 <= n)
  {
    while (ind != j)
    {
      a[(j + 1) % n] = a[j] - (c[j][0] - c[(j + 1) % n][0]); // a[j] - (c[j][0] - c[(j + 1) % n][0] > 0 とは限らない．
      j = (j + 1) % n;
    }
  }

  REP(i, n)
  {
    b[i] = c[0][i] - a[0];
  }

  REP(i, n)
  {
    REP(j, n)
    {
      if (b[i] != c[j][i] - a[j])
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  REP(i, n)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  REP(i, n)
  {
    cout << b[i] << " ";
  }
  cout << endl;

  return 0;
}
*/