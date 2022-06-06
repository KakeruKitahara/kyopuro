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
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;

  int mians = -1;
  int maans = -1;

  REP2(i, a, b + 1)
  {
    int n = w / i;
    int r = w % i;
    if (r == 0)
    {
      mians = n;
      break;
    }
    if (n * (b - i) >= r)
    {
      mians = n;
      break;
    }
  }

  REPR2(i, b, a)
  {
    int n = w / i;
    int r = w % i;
    if (r == 0)
    {
      maans = n;
      break;
    }
    if (n * (i - a) + r >= a)
    {
      maans = n + 1;
      break;
    }
  }

  if (mians == -1 && maans == -1)
  {
    cout << "UNSATISFIABLE" << endl;
  }
  else
  {
    cout << maans << " " << mians << endl;
  }

  return 0;
}