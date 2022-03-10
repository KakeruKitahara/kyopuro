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
  vector<vector<double>> a(n, vector<double>(3));
  REP(i, n)
  {
    cin >> a[i][2] >> a[i][0] >> a[i][1];
    if (a[i][2] == 2 || a[i][2] == 4)
    {
      a[i][1] -= 0.5;
    }
    if (a[i][2] == 3 || a[i][2] == 4)
    {
      a[i][0] += 0.5;
    }
  }

  vector<P> ans;
  P tmp;
  REP(i, n)
  {
    REP2(j, 1, n)
    {
      if (a[i][0] <= a[j][0] && a[j][0] <= a[i][1])
      {
        tmp.first = a[j][0];
        tmp.second = a[i][1];
        ans.push_back(tmp);
      }
      else if (a[i][0] <= a[j][1] && a[j][1] <= a[i][1])
      {
        tmp.first = a[i][0];
        tmp.second = a[j][1];
        ans.push_back(tmp);
      }
      else if (a[j][0] <= a[i][0] && a[i][0] <= a[j][1])
      {
        tmp.first = a[j][0];
        tmp.second = a[i][1];
        ans.push_back(tmp);
      }
      else if (a[j][0] <= a[i][1] && a[i][1] <= a[j][1])
      {
        tmp.first = a[i][0];
        tmp.second = a[j][1];
        ans.push_back(tmp);
      }
    }
  }
  cout << ans.size() << endl;
  return 0;
}