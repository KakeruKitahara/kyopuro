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
  int n, x;
  cin >> n >> x;
  V a(n + 1);
  bool b[n + 1];
  REP2(i, 1, n + 1)
  {
    cin >> a[i];
    b[i] = false;
  }

  int k = x;
  while (1)
  {
    b[k] = true;
    if (b[a[k]] == true)
    {
      break;
    }
    k = a[k];
  }

  int cnt = 0;
  REP2(i, 1, n + 1)
  {
    if (b[i] == true)
    {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}