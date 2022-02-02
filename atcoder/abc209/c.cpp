#include <bits/stdc++.h>
using namespace std;
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

int main()
{

  int n;
  cin >> n;
  vector<ll> c(n);

  REP(i, n)
  {
    cin >> c[i];
  }

  ll max = 0;
  sort(c.begin(), c.end());

  REP(i, n)
  {
    max += c[i];
  }
  ll dp = 0;
  REP(i, n)
  {
    max -= c[i];
    dp += (max - (n - i - 1)) % 1000000007;
  }
  cout << dp << " " << endl;

  return 0;
}