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
  int n;
  cin >> n;
  VVl a(n);
  VV q(n);
  REP(i, n)
  {
    int t, v;
    cin >> t >> v;
    REP(j, t)
    {
      int te;
      cin >> te;
      a[i].push_back(te);
    }
    REP(j, v)
    {
      int te;
      cin >> te;
      q[i].push_back(te);
    }
  }

  REP(i, n)
  {
    sort(a[i].rbegin(), a[i].rend());
  }

  VV sum(n);
  REP(i, n)
  {
    ll sums = 0;
    REP(j, a[i].size())
    {
      sums += a[i][j];
      sum[i].push_back(sums);
    }
  }

  REP(i, n)
  {
    REP(j, q[i].size())
    {
      auto it = lower_bound(sum[i].begin(), sum[i].end(), q[i][j]);
      if (it == sum[i].end())
      {
        cout << -1 << endl;
      }
      else
      {
        cout << it - sum[i].begin() + 1 << endl;
      }
    }
  }

  return 0;
}