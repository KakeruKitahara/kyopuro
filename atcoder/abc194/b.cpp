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
  int a[n], b[n];
  REP(i, n)
  {
    cin >> a[i] >> b[i];
  }

  int mina = 10E+5, minb = 10E+5;
  int tmp = 10E+5;
  int iam = 0, ibm = 0;

  REP(i, n)
  {
    if (mina > a[i])
    {
      mina = a[i];
      iam = i;
    }
  }
  REP(i, n)
  {
    if (iam == i)
    {
      minb = (minb, b[i] + mina);
    }
    else
    {
      tmp = min(tmp, b[i]);
    }
  }
  minb = min(max(mina, tmp), minb);
  cout << minb;
  return 0;
}