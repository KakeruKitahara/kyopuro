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
  int n, k;
  cin >> n >> k;
  VV a(n, V(n));
  REP(i, n)
  {
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }
  V ansa;
  REP(i, n - (k - 1) + 1)
  {
    REP(j, n - (k - 1) + 1)
    {
      V tmp;
      REP2(m, i, k)
      {
        REP2(l, j, k)
        {
          tmp.push_back(a[m][l]);
        }
      }
      for (int i = 0; i < k * k; i++)
      {
        cout << tmp[i] << (i < k * k - 1 )? ' ' : '\n';
      }

      sort(tmp.begin(), tmp.end());
      ansa.push_back(tmp[floor(k * k / 2)]);
    }
  }
  sort(ansa.begin(), ansa.end());
  cout << ansa[0] << endl;
  return 0;
}