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

VV a;
V x, y;
int n, m;

int dfs(int ptr, int i, int j, int sum)
{
  sum += a[i][j];
  cout << i << " " << j << " " << a[i][j] << endl;

  if (j == n - 1)
  {
    return sum;
  }
  int tmp = INF;

  REP(k, n)
  {
    int flag = 0;
    REP(z, m)
    {
      if (a[k][j + 1] == x[z] && a[i][j] == y[z] || a[k][j + 1] == y[z] && a[i][j] == x[z])
      {
        flag = 1;
      }
    }
    if (flag == 0)
    {
      tmp = min(dfs(a[k][j + 1], k, j + 1, sum), tmp);
    }
  }

  return tmp;
}

int main()
{

  cin >> n;

  a.resize(n);
  REP(i, n)
  {
    a[i].resize(n);
  }

  REP(i, n)
  {
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }

  cin >> m;

  x.resize(m);
  y.resize(m);
  REP(i, m)
  {
    cin >> x[i] >> y[i];
  }

  int tmp = INF;
  int sum = 0;
  REP(i, n)
  {
    tmp = min(dfs(a[i][0], i, 0, sum), tmp);
  }

  if (tmp == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << tmp << endl;
  }
}