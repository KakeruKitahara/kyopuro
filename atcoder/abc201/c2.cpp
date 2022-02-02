#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;

int main()
{
  S s;
  cin >> s;

  int m = 0;
  REP(i, 10)
  {
    if (s[i] == 'o')
      m++;
  }

  int ans = 0;

  REP(i, 10000)
  {
    int pass[4];
    int tmp = i;
    REPR(j, 4)
    {
      pass[j] = tmp % 10;
      tmp /= 10;
    }
    int jd[10] = {};

    int no = 0;
    REP(k, 4)
    {
      if (s[pass[k]] == 'o')
      {
        jd[pass[k]] = 1;
      }
      if (s[pass[k]] == 'x')
      {
        no = 1;
      }
    }

    int flag = 0;
    REP(j, 10)
    {
      if (jd[j] == 1)
      {
        flag++;
      }
    }
    if (flag == m && no == 0)
    {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}