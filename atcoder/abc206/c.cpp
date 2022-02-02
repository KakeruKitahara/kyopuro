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
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  map<int, int> m;
  REP(i, n)
  {
    if (m.count(a[i]))
    {
      m[a[i]]++;
    }
    else
    {
      m[a[i]] = 1;
    }
  }
  ll sum = 0;
  for (const auto [key, value] : m)
  {
    sum += ll(value) * (value - 1) / 2;
  }
  cout << ll(n) * (n - 1) / 2 - sum << endl;
  return 0;
}