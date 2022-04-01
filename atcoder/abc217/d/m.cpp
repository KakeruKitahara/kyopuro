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
  int l, q;
  cin >> l >> q;
  vector<P> qr(q);

  REP(i, q)
  {
    cin >> qr[i].first >> qr[i].second;
  }

  set<int> e;
  e.insert(0);
  REP(i, q)
  {
    if (qr[i].first == 1)
    {
      e.insert(qr[i].second);
    }
  }
  e.insert(l);

  V ans;

  REPR(i, q)
  {
    if (qr[i].first == 1)
    {
      auto it = e.lower_bound(qr[i].second);
      e.erase(it);
    }
    else
    {
      auto it = e.lower_bound(qr[i].second);
      auto it2 = e.lower_bound(qr[i].second);
      it--;

      ans.push_back(*it2 - *it);
    }
  }

  REPR(i, ans.size())
  {
    cout << ans[i] << endl;
  }

  return 0;
}