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

int main()
{
  int v, t, s, d;
  cin >> v >> t >> s >> d;
  int vt, vs;
  vt = v * t;
  vs = v * s;
  if (vt <= d && d < vs)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}