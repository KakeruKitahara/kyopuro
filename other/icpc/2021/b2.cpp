#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;

V cnt;
V jd(201);
VV edge(201);

void dfs(int ptr)
{
  jd[ptr] = 1;
  cnt.push_back(ptr);

  REP(i, edge[ptr].size())
  {
    if (jd[edge[ptr][i]] == 0)
    {
      dfs(edge[ptr][i]);
    }
  }
}

int main()
{
  VV x, y;
  V w, h;
  while (1)
  {
    int ww, hh;
    cin >> ww >> hh;
    if (ww == 0 && hh == 0)
    {
      break;
    }
    else
    {
      w.push_back(ww);
      h.push_back(hh);
    }
    V xx(ww + hh - 1), yy(ww + hh - 1);
    int n;
    REP(i, ww + hh - 1)
    {
      cin >> xx[i] >> yy[i] >> n;
    }

    x.push_back(xx);
    y.push_back(yy);
  }

  int t = w.size();

  REP(i, t)
  {

    REP(j, x[i].size())
    {
      edge[x[i][j]].push_back(y[i][j] + 100);
      edge[y[i][j] + 100].push_back(x[i][j]);
    }

    REP(j, edge[1].size())
    {
      if (jd[edge[1][j]] == 0)
      {
        dfs(edge[1][j]);
      }
    }
    V ansh(h[i]);
    V answ(w[i]);
    REP(j, cnt.size())
    {
      if (cnt[j] > 100)
      {
        ansh[cnt[j] - 101]++;
      }
      else
      {
        answ[cnt[j] - 1]++;
      }
    }
    int f1 = 0, f2 = 0;
    REP(j, h[i])
    {
      if (ansh[j] > 0)
      {
        f1++;
      }
    }
    REP(j, w[i])
    {
      if (answ[j] > 0)
      {
        f2++;
      }
    }

    if (f1 == h[i] && f2 == w[i])
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }

    jd.clear();
    jd.resize(201);
    cnt.clear();
    edge.clear();
    edge.resize(201);
  }
  return 0;
}