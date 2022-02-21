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

int main()
{
  int n, q;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  cin >> q;
  V b(q);
  REP(i, q)
  {
    cin >> b[i];
  }

  sort(a.begin(), a.end());

  REP(i, q)
  {
    int left = 0, right = n - 1, key;
    while (1)
    {
      key = (left + right) / 2;
      if (left == key)
      {
        cout << min(abs(a[left] - b[i]), abs(a[right] - b[i])) << endl;
        break;
      }
      if (b[i] - a[key] < 0)
      {
        right = key;
      }
      else if (b[i] - a[key] > 0)
      {
        left = key;
      }
      else if (b[i] - a[key] == 0)
      {
        cout << abs(a[key] - b[i]) << endl;
        break;
      }
    }
  }

  return 0;
}