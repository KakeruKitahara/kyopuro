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
V h, w;
VV table;
int dfsw(int ptr_y, int ptr_x);
int dfsr(int ptr_y, int ptr_x);

int dfsr(int ptr_y, int ptr_x)
{
  REP(j, h.size())
  {
    if ((ptr_y != j) && (table[j][ptr_x] != INF))
    {
      h[j] = table[j][ptr_x] - w[ptr_x];
      table[j][ptr_x] = INF;
      dfsw(j, ptr_x);
    }
  }

  return 0;
}

int dfsw(int ptr_y, int ptr_x)
{

  REP(i, w.size())
  {
    if ((ptr_x != i) && (table[ptr_y][i] != INF))
    {
      w[i] = table[ptr_y][i] - h[ptr_y];
      table[ptr_y][i] = INF;
      dfsr(ptr_y, i);
    }
  }

  return 0;
}

int main()
{
  vector<string> a;
  while (1)
  {
    ll height, width;
    cin >> height >> width;
    if (height == 0 && width == 0)
    {
      REP(i, a.size())
      {
        cout << a[i] << endl;
      }
      return 0;
    }

    h.resize(height + 1);
    REP(i, h.size())
    {
      h[i] = INF;
    }
    w.resize(width + 1);
    REP(i, w.size())
    {
      w[i] = INF;
    }
    table.resize(height + 1);
    REP(i, table.size())
    {
      table[i].resize(width + 1);
      REP(j, table[i].size())
      {
        table[i][j] = INF;
      }
    }

    int x, y, n;
    REP(i, height + width - 1)
    {
      cin >> x >> y >> n;
      table[x][y] = n;
    }

    w[1] = 0;
    REP2(i, 1, height + 1)
    {
      if (table[i][1] != INF)
      {
        h[i] = table[i][1];
      }
    }

    REP2(i, 1, height + 1)
    {
      if (h[i] != INF)
      {
        dfsw(i, 1);
      }
    }
    int flag = 0;

    REP2(i, 1, height + 1)
    {
      if (h[i] == INF || w[i] == INF)
      {
        a.push_back(std::string("NO"));
        flag = 1;
        break;
      }
    }
    if (flag == 1)
    {
      continue;
    }
    a.push_back(std::string("YES"));
    h.clear();
    w.clear();
    table.clear();
  }

  return 0;
}