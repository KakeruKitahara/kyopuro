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
  VV e(n);

  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  int q;
  cin >> q;
  V x(q), k(q);
  REP(i, q)
  {
    cin >> x[i] >> k[i];
    x[i]--;
  }
  V jd(n); // 生成にO(n);

  REP(i, q)
  {
    ll ans = 0;
    queue<P> qu;
    qu.push(make_pair(x[i], 0));
    V anss;

    jd[x[i]] = 1;

    while (qu.size() != 0)
    {
      P ptr = qu.front();
      qu.pop();
      anss.push_back(ptr.first);

      if (ptr.second == k[i])
      {
        continue;
      }
      REP(j, e[ptr.first].size())
      {
        if (jd[e[ptr.first][j]] == 0)
        {
          qu.push(make_pair(e[ptr.first][j], ptr.second + 1));
          jd[e[ptr.first][j]] = 1;
        }
      }
    }
    REP(i, anss.size())
    {
      ans += anss[i] + 1;
      jd[anss[i]] = 0;
    }
    cout << ans << endl;
  }

  return 0;
}