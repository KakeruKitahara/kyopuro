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

int main()
{
  int t, n;
  cin >> t >> n;

  ll tmp = n * 100LL;
  ll num = (tmp + t - 1) / t;
  cout << num * (100 + t) / 100 - 1 << endl;
  return 0;
}