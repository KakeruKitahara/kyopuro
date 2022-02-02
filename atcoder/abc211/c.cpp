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
  S s;
  cin >> s;

  vector<int> p(8);

  S c = "chokudai";

  REP(i, s.size())
  {
    if (s[i] == 'c')
    {
      p[0] = (p[0] + 1);
    }
    REP2(j, 1, 8)
    {
      if (s[i] == c[j])
      {
        p[j] = (p[j] + p[j - 1]) % 1000000007;
      }
    }
  }

  cout << p[7] % 1000000007 << endl;
  return 0;
}