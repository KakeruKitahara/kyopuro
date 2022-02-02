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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int q;
  cin >> q;
  V que;
  Vl x(q);

  REP(i, q)
  {
    int t;
    cin >> t;
    que.push_back(t);
    if (t != 3)
    {
      cin >> x[i];
    }
  }

  Vl plus(q);
  multiset<ll> bag;
  REP(i, q)
  {
    if (i != 0)
    {
      plus[i] = plus[i - 1];
    }

    if (que[i] == 1)
    {
      bag.insert(x[i] - plus[i]);
    }
    else if (que[i] == 2)
    {
      plus[i] = x[i] + plus[i - 1];
    }
    else
    {
      cout << *(bag.begin()) + plus[i] << endl;
      bag.erase(bag.begin());
    }
  }

  return 0;
}