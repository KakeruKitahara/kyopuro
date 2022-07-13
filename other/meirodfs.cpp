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

VV jd;
int h, w;

int dfs(P ptr, int num)
{
  P wk[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
  jd[ptr.first][ptr.second] = 1;
  num++;

  int num2 = num;
  REP(i, 4)
  {
    P next;
    next.first = ptr.first + wk[i].first;
    next.second = ptr.second + wk[i].second;
    if (0 <= next.first && next.first < h && 0 <= next.second && next.second < w)
    {
      if (jd[next.first][next.second] == 0)
      {
        num += dfs(next, num2) - num2;
      }
    }
  }

  return num;
}

void solve(int w, int h)
{
  P s;
  jd.resize(h);
  REP(i, h)
  {
    jd[i].resize(w);
    REP(j, w)
    {
      char c;
      cin >> c;
      if (c == '#')
      {
        jd[i][j] = 1;
      }
      else if (c == '@')
      {
        s.first = i;
        s.second = j;
      }
    }
  }

  cout << dfs(s, 0) << endl;

  jd.clear();
}

int main()
{
  while (1)
  {

    cin >> w >> h;
    if (w == 0 && h == 0)
    {
      break;
    }
    solve(w, h);
  }

  return 0;
}