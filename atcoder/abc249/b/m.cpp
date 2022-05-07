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
  S s;
  cin >> s;
  V a(10000);

  REP(i, s.size())
  {
    a[s[i]]++;
  }

  REP(i, 10000)
  {
    if (a[i] >= 2)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  int f = 0, f1 = 0;
  REP(i, 10000)
  {
    if ('a' <= i && i<= 'z')
    {
      if (a[i] == 1)
      {
        f = 1;
      }
    }
    if ('A' <= i && i <= 'Z')
    {
      if (a[i] == 1)
      {
        f1 = 1;
      }
    }
  }

  if (f == 1 && f1 == 1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}