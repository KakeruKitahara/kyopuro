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

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  int key;
  int flg = 0;

  REP(i, n)
  {
    if (i == n - 1)
    {
      key = a[n - 1];
      break;
    }

    if (a[i] > a[i + 1])
    {
      key = a[i];
      break;
    }

    if (a[i] < a[i + 1])
    {
      key = a[i + 1];
      flg = 1;
    }

    if (flg == 1 && a[i] > a[i + 1])
    {
      break;
    }
  }

  REP(i, n)
  {
    if (a[i] == key)
      continue;
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}