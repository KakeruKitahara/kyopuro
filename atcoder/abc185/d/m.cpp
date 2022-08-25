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
  int n, m;
  cin >> n >> m;
  if (m == 0)
  {
    cout << "1" << endl;
    return 0;
  }
  V a(m);
  REP(i, m)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  V ans;
  ans.push_back(a[0] - 1);
  REP(i, m)
  {
    int tmp;
    if (i == m - 1)
    {
      tmp = n + 1 - a[m - 1] - 1;
    }
    else
    {
      tmp = a[i + 1] - a[i] - 1;
    }
    ans.push_back(tmp);
  }
  sort(ans.begin(), ans.end());

  if (ans[m] == 0)
  {
    cout << "0" << endl;
    return 0;
  }
  int k = 0;
  REP(i, m + 1)
  {
    if (ans[i] != 0)
    {
      k = ans[i];
      break;
    }
  }

  int sum = 0;
  sum += (a[0] - 1 + k - 1) / k;
  REP(i, m)
  {
    if (i == m - 1)
    {
      sum += (n + 1 - a[m - 1] - 1 + k - 1) / k;
    }
    else
    {
      sum += (a[i + 1] - a[i] - 1 + k - 1) / k;
    }
  }
  cout << sum << endl;

  return 0;
}