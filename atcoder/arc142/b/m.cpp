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
  int n;
  cin >> n;
  VV aa, bb;

  REP(i, n)
  {
    V a;
    REP2(j, 1, n + 1)
    {
      a.push_back(i * n + j);
    }

    if (n % 2 == 1)
    {
      if (i <= n / 2)
      {
        aa.push_back(a);
      }
      else
      {
        bb.push_back(a);
      }
    }
    else
    {
      if (i < n / 2)
      {
        aa.push_back(a);
      }
      else
      {
        bb.push_back(a);
      }
    }
  }

  int ai = 0, bi = 0;

  REP(i, n)
  {
    if (i % 2 == 0)
    {
      REP(j, n)
      {
        cout << aa[ai][j] << " ";
      }
      ai++;
    }
    else
    {
      REP(j, n)
      {
        cout << bb[bi][j] << " ";
      }
      bi++;
    }
    cout << endl;
  }

  return 0;
}