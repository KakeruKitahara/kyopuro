#include <bits/stdc++.h>
using namespace std;
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

int main()
{
  int t;
  cin >> t;
  V l1(t), r1(t), l2(t), r2(t);
  REP(i, t)
  {
    cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
  }

  REP(i, t)
  {
    if (l1[i] <= l2[i] && l2[i] <= r1[i] && r1[i] <= r2[i])
    {
      cout << l2[i] << endl;
    }
    else if (l2[i] <= l1[i] && l1[i] <= r2[i] && r2[i] <= r1[i])
    {
      cout << l1[i] << endl;
    }
    else if (l1[i] <= l2[i] && l2[i] <= r2[i] && r2[i] <= r1[i])
    {
      cout << l2[i] << endl;
    }
    else if (l2[i] <= l1[i] && l1[i] <= r1[i] && r1[i] <= r2[i])
    {
      cout << l1[i] << endl;
    }
    else
    {
      cout << l1[i] + l2[i] << endl;
    }
  }

  return 0;
}