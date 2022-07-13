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
  int n, m;
  cin >> n >> m;
  V a(m), b(m), c(m);

  vector<vector<P>> e(n);

  ll ans = 0;

  REP(i, m)
  {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    e[a[i]].push_back(make_pair(b[i], c[i]));
    e[b[i]].push_back(make_pair(a[i], c[i]));
    ans += c[i];
  }

  V jd(n);
  map<P, int> cost;

  queue<int> q;

  q.push(0);

  while (q.size() != 0)
  {
    int ptr = q.front();
    q.pop();
    jd[ptr] = 1;

    REP(i, e[ptr].size())
    {
      if (jd[e[ptr][i].first] != 1)
      {
        q.push(e[ptr][i].first);
      }
      if (cost.count(make_pair(min(ptr, e[ptr][i].first), max(ptr, e[ptr][i].first))) == 0)
      {
        cost[make_pair(min(ptr, e[ptr][i].first), max(ptr, e[ptr][i].first))] = e[ptr][i].second;
      }
      else
      {
        cost[make_pair(min(ptr, e[ptr][i].first), max(ptr, e[ptr][i].first))] = min(cost[make_pair(min(ptr, e[ptr][i].first), max(ptr, e[ptr][i].first))], e[ptr][i].second);
      }
    }
  }

  ll sum = 0;
  for(pair<P, int> a : cost)
  {
    sum += a.second;
  }

  cout << ans - sum << endl;

  return 0;
}