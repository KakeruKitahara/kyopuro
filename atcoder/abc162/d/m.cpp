#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

int main()
{
  int n;
  cin >> n;
  S s;
  cin >> s;

  ll all = 0;
  V c(3);
  REP(i, n)
  {
    if (s[i] == 'R')
    {
      c[0]++;
    }
    else if (s[i] == 'G')
    {
      c[1]++;
    }
    else
    {
      c[2]++;
    }
  }

  ll alls = c[0];

  alls = alls * c[1] * c[2];
  ll cnt = 0;
  REP(i, n)
  {
    REP2(j, 1, n)
    {
      if (i + 2 * j < n && s[i] != s[i + j] && s[i + j] != s[i + 2 * j] && s[i] != s[i + 2 * j])
      {
        cnt++;
      }
    }
  }

  cout << alls - cnt << endl;
  return 0;
}