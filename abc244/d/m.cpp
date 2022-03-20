#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

int main()
{
  S s1[3], t1[3];
  REP(i, 3){
    cin >> s1[i];
  }
  REP(i, 3){
    cin >> t1[i];
  }

  S s = s1[0] + s1[1] + s1[2];
  
  S t = t1[0] + t1[1] + t1[2];
  S a[3] = {"GRB", "RBG", "BGR"};
  S b[3] = {"RGB", "GBR", "BRG"};

  int f = 0;
  REP(i, 3)
  {
    if (s == a[i])
    {
      f = 1;
    }
    else if (s == b[i])
    {
      f = 2;
    }
  }
  if (f == 1)
  {
    REP(i, 3)
    {
      if (t == a[i])
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  else if (f == 2)
  {
    REP(i, 3)
    {
      if (t == b[i])
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}