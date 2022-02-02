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
  ll k;
  cin >> n >> k;
  vector<pair<ll, ll>> a(n);
  REP(i, n)
  {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());

  ll tmp = k % n;

  REP(i, n)
  {
    if (i < tmp)
    {
      a[i].first = a[i].second;
      a[i].second = k / n + 1;
    }
    else
    {
      a[i].first = a[i].second;
      a[i].second = k / n;
    }
  }
  sort(a.begin(), a.end());
  REP(i, n)
  {
    cout << a[i].second << endl;
  }
  return 0;
}