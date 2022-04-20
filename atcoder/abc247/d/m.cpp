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
  vector<pair<ll, ll>> in(q);
  V jd(q), out(q);
  REP(i, q)
  {
    cin >> jd[i];
    if (jd[i] == 1)
    {
      int x, b;
      cin >> x >> b;
      in[i] = make_pair(x, b);
    }
    else
    {
      cin >> out[i];
    }
  }
  deque<pair<ll, ll>> t;
  ll ans = 0;

  REP(i, q)
  {
    if (jd[i] == 1)
    {
      t.push_back(in[i]);
    }
    else
    {
      int to = out[i];
      while (1)
      {
        if (t.front().second >= to)
        {
          ans += to * t.front().first;

          P tmp;
          tmp.first = t.front().first;
          tmp.second = t.front().second - to;
          t.pop_front();
          t.push_front(tmp);
          break;
        }
        else
        {
          ans += t.front().second * t.front().first;
          to -= t.front().second;
          t.pop_front();
        }
      }
      cout << ans << endl;
      ans = 0;
    }
  }

  return 0;
}