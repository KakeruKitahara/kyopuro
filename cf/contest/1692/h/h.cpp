#include <bits/stdc++.h>
using namespace std;
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
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;

int main()
{
  int t;
  cin >> t;
  VV a(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    a[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }

  REP(i, t)
  {
    map<int, tuple<int, int, int>> on;
    map<int, tuple<int, int, int>> maxs;
    int prev = a[i][0];
    REP(j, a[i].size())
    {
      int &c = get<0>(on[a[i][j]]);
      int &d = get<1>(on[a[i][j]]);
      int &e = get<2>(on[a[i][j]]);
      if (c == 0)
      {
        d = j;
      }
      else if (prev != a[i][j])
      {
        if (j - e - 1 >= c)
        {
          d = j;
          c = 0;
        }
        else
        {
          c -= j - e - 1;
        }
      }

      c++;
      e = j;

      if (get<0>(maxs[a[i][j]]) < c)
      {
        maxs[a[i][j]] = on[a[i][j]];
      }
      prev = a[i][j];
    }

    int maxs2 = -1;
    tuple<int, int, int> ans;
    int ind = 0;
    for (pair<int, tuple<int, int, int>> x : maxs)
    {
      if (get<0>(x.second) > maxs2)
      {
        ind = x.first;
        ans = x.second;
        maxs2 = get<0>(x.second);
      }
    }

    cout << ind << " " << get<1>(ans) + 1 << " " << get<2>(ans) + 1 << endl;
  }

  return 0;
}