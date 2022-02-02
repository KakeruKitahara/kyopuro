#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int dfs(V A, int q, int n, int m, int a[], int b[], int c[], int d[])
{
  REP(i, n)
  {
    cout << A[i] << " ";
  }
  cout << "\n";
  int ans = -1;
  if (A[0] == m)
  {
    int sum = 0;
    REP(i, q)
    {
      if (A[a[i]] - A[b[i]] == c[i])
      {
        sum += d[i];
      }
    }

    ans = max(ans, sum);

    return ans;
  }

  if (A[n - 1] != m)
  {
    int tmp = A[n - 1];
    A[n - 1]++;
    ans = (ans, dfs(A, q, n, m, a, b, c, d));
    A[n - 1]--;
  }
  REPR(i, n - 1)
  {
    if (A[i] != m)
    {
      if (A[i + 1] > A[i])
      {
        A[i]++;
        ans = (ans, dfs(A, q, n, m, a, b, c, d));
        A[i]--;
      }
    }
  }

  int sum = 0;
  REP(i, q)
  {
    if (A[a[i]] - A[b[i]] == c[i])
    {
      sum += d[i];
    }
  }

  ans = max(ans, sum);

  return ans;
}

int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  int a[q], b[q], c[q], d[q];
  REP(i, q)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  V A(n, 1);

  int ans = dfs(A, q, n, m, a, b, c, d);
  cout << ans;

  return 0;
}