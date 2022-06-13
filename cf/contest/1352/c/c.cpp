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
  Vl n(t), k(t);
  REP(i, t)
  {
    cin >> n[i] >> k[i];
  }

  REP(i, t)
  {
    ll a = ((k[i] + n[i] - 2) / (n[i] - 1) - 1);
    ll b = k[i] % (n[i] - 1);
    if (b == 0)
    {
      b = n[i] - 1;
    }
    cout << a * n[i] + b << endl;
  }

  return 0;
}