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
  S s, tmpf, tmpe;
  char tmp;
  int n, q, cnt = 0;
  cin >> n >> s >> q;
  int t[q], a[q], b[q];
  REP(i, q)
  {
    cin >> t[i] >> a[i] >> b[i];
  }
  int k = 0, k2 = 0, a2, b2;
  REP(i, q)
  {
    if (t[i] == 1)
    {
      if (a[i] - 1 < n)
      {
        a2 = a[i] + k - 1;
      }
      else
      {
        a2 = a[i] + k2 - 1;
      }
      if (b[i] - 1 < n)
      {
        b2 = b[i] + k - 1;
      }
      else
      {
        b2 = b[i] + k2 - 1;
      }
      tmp = s[a2];
      s[a2] = s[b2];
      s[b2] = tmp;
    }
    if (t[i] == 2)
    {
      cnt++;
      if (cnt % 2 == 0)
      {
        k = 0;
        k2 = 0;
      }
      else
      {
        k = n;
        k2 = -n;
      }
    }
  }

  if (cnt % 2 == 0)
  {
    cout << s << endl;
  }
  else
  {
    tmpf = s.substr(0, n);
    tmpe = s.substr(n, n);
    s.replace(0, n, tmpe);
    s.replace(n, n, tmpf);
    cout << s << endl;
  }
  return 0;
}