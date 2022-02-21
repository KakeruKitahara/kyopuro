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
  int q;
  cin >> q;
  V b(q);
  REP(i, q)
  {
    cin >> b[i];
  }

  sort(a.begin(), a.end());

  REP(i, q)
  {
    int k;
    auto it = lower_bound(a.begin(), a.end(), b[i]);
    if (it == a.begin())
    {
      k = abs(*it - b[i]);
    }
    else if (it == a.end())
    {
      k = abs(*(it - 1) - b[i]);
    }
    else
    {
      k = min(abs(*(it - 1) - b[i]), abs(*it - b[i]));
    }
    cout << k << endl;
  }
  return 0;
}