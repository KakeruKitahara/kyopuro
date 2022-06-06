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
  VV da;
  while (1)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
      break;
    }
    V v = {a, b, c, d};
    da.push_back(v);
  }

  REP(i, da.size())
  {
    sort(da[i].begin(), da[i].end());
    auto kk = lower_bound(da[i].begin(), da[i].end(), 1);
    while (kk != da[i].end() - 1)
    {
      for (auto j = lower_bound(da[i].begin(), da[i].end(), 1) + 1; j != da[i].end(); j++)
      {
        *j -= *kk;
      }
      sort(da[i].begin(), da[i].end());
      kk = lower_bound(da[i].begin(), da[i].end(), 1);
    }
    cout << *kk << endl;
  }

  return 0;
}