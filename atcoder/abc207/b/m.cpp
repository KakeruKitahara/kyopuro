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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll bu = a, re = 0, cnt = 0;
  if (b >= c * d)
  {
    cout << "-1" << endl;
    return 0;
  }
  while (1)
  {
    if (re >= bu)
    {
      break;
    }
    cnt++;
    bu += b;
    re += c * d;
  }

  cout << cnt << endl;
  return 0;
}