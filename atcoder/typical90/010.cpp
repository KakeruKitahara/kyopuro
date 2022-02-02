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
  int n;
  cin >> n;
  int c[n], p[n];
  REP(i, n)
  {
    cin >> c[i] >> p[i];
  }
  int q;
  cin >> q;
  int l[q], r[q];
  REP(i, q)
  {
    cin >> l[i] >> r[i];
  }

  int sum1[n], sum2[n];
  if (c[0] == 1)
  {
    sum1[0] = p[0];
  }
  else
  {
    sum2[0] = p[0];
  }

  REP2(i, 1, n)
  {
    if (c[i] == 1)
    {
      sum1[i] = sum1[i- 1] + p[i];
      sum2[i] = sum2[i - 1];
    }
    else
    {
      sum2[i] = sum2[i - 1] + p[i];
      sum1[i] = sum1[i - 1];
    }
  }

  REP(i, q)
  {int tmp[2];
    if(c[l[i] - 1] == 1){
      tmp[0] = p[l[i] - 1];
      tmp[1] = 0;
    }
    else
    {
      tmp[0] = 0;
      tmp[1] = p[l[i] - 1];
    }
    cout << sum1[r[i] - 1] - sum1[l[i] - 1] + tmp[0] << " " << sum2[r[i] - 1] - sum2[l[i] - 1] + tmp[1] << endl;
  }

  return 0;
}