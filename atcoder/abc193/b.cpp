#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n], p[n], x[n];

  int mins = 1E+9 + 1;

  REP(i, n)
  {
    cin >> a[i] >> p[i] >> x[i];
    if (x[i] - a[i] > 0)
    {
      mins = min(mins, p[i]);
    }
  }

  if (mins == 1E+9 + 1)
  {
    cout << "-1" << endl;
  }
  else
  {
    cout << mins << endl;
  }
}