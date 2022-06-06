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
vector<VV> edge;
VV jd;
vector<VV> tmppath;
V s = {-1};

void dfs(int ptr, int k)
{
  tmppath[k][tmppath[k].size() - 1].push_back(ptr + 1);
  jd[k][ptr] = 1;

  REP(i, edge[k][ptr].size())
  {
    if (jd[k][edge[k][ptr][i]] == 0)
    {
      dfs(edge[k][ptr][i], k);
      tmppath[k].push_back(s);
    }
  }

  return;
}

int main()
{
  int t;
  cin >> t;
  VV p(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    REP(j, n)
    {
      int k;
      cin >> k;
      k--;
      p[i].push_back(k);
    }
  }

  edge.resize(t);
  jd.resize(t);
  tmppath.resize(t);

  REP(i, t)
  {
    edge[i].resize(p[i].size());
    jd[i].resize(p[i].size());
    int u;
    REP(j, p[i].size())
    {
      if (p[i][j] == j)
      {
        u = j;
      }
      else
      {
        edge[i][j].push_back(p[i][j]);
        edge[i][p[i][j]].push_back(j);
      }
    }

    tmppath[i].push_back(s);
    dfs(u, i);

    int cnt = 0;
    REP(j, tmppath[i].size())
    {
      if (tmppath[i][j].size() >= 2)
      {
        cnt++;
      }
    }

    cout << cnt << endl;
    REP(j, tmppath[i].size())
    {
      if (tmppath[i][j].size() >= 2)
      {
        cout << tmppath[i][j].size() - 1 << endl;
        REP2(l, 1, tmppath[i][j].size())
        {
          cout << tmppath[i][j][l] << " ";
        }
        cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}