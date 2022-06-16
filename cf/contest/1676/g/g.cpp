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
ll ans;
VV edge;
V jd;
S s;

P dfs(int ptr, P wb)
{

  P sum = make_pair(0, 0);
  REP(i, edge[ptr].size())
  {
    jd[ptr] = 1;
    if (jd[edge[ptr][i]] == 0)
    {
      P tmp = dfs(edge[ptr][i], make_pair(0, 0));
      sum.first += tmp.first;
      sum.second += tmp.second;
    }
  }

  if (s[ptr] == 'W')
  {
    sum.first++;
  }
  else
  {
    sum.second++;
  }

  if (sum.first == sum.second)
  {
    ans++;
  }

  return sum;
}

int main()
{

  int t;
  cin >> t;
  VV a(t);
  vector<S> ss(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    a[i].resize(n - 1);
    REP(j, n - 1)
    {
      cin >> a[i][j];
      a[i][j]--;
    }
    cin >> ss[i];
  }

  REP(i, t)
  {
    ans = 0;
    VV tmpe(a[i].size() + 1);
    V tmpjd(a[i].size() + 1);
    REP(j, a[i].size())
    {
      tmpe[j + 1].push_back(a[i][j]);
      tmpe[a[i][j]].push_back(j + 1);
    }

    edge = tmpe;
    jd = tmpjd;
    s = ss[i];

    dfs(0, make_pair(0, 0));

    cout << ans << endl;
  }

  return 0;
}