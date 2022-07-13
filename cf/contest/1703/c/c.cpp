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

void solve()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  vector<S> b(n);
  REP(i, n)
  {
    int k;
    cin >> k;
    cin >> b[i];
  }

  REP(i, n)
  {
    REP(j, b[i].size())
    {
      if (b[i][j] == 'D')
      {
        a[i]++;
        if (a[i] == 10)
        {
          a[i] = 0;
        }
      }
      else
      {
        a[i]--;
        if (a[i] == -1)
        {
          a[i] = 9;
        }
      }
    }
  }

  REP(i, n)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}