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
  int q;
  cin >> q;
  multiset<ll> se;
  REP(i, q)
  {
    ll x;
    int a, k;
    cin >> a;
    if (a == 1)
    {
      cin >> x;
      se.insert(x);
    }
    else if (a == 2)
    {
      cin >> x >> k;
      auto it = se.upper_bound(x);
      if (it == se.begin())
      {
        cout << -1 << endl;
        continue;
      }
      REP(j, 5)
      {
        it--;
        if (j == k - 1)
        {
          cout << *it << endl;
          break;
        }
        if (it == se.begin())
        {
          cout << -1 << endl;
          break;
        }
      }

    }
    else
    {
      cin >> x >> k;
      auto it = se.lower_bound(x);
      REP(j, 5)
      {
        if (it == se.end())
        {
          cout << -1 << endl;
          break;
        }
        if (j == k - 1)
        {
          cout << *it << endl;
          break;
        }
        it++;
      }
    }
  }

  return 0;
}