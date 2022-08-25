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
  int r, c;
  cin >> r >> c;
  r--;
  c--;

  VV mp(15, V(15));
  REP(i, 15)
  {
    REP(j, 15)
    {
      if (i % 2 == 0)
      {
        mp[i][j] = 1;
      }
    }
  }

  int cc = 0;

  REP(j, 15)
  {
    int k = mp[cc][j];
    REP2(i, min(cc, 15 - cc), max(15 - cc, cc))
    {
      mp[i][j] = k;
    }
    cc++;
  }



  if (mp[r][c] == 0)
  {
    cout << "white" << endl;
  }
  else
  {
    cout << "black" << endl;
  }
  return 0;
}