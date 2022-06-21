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

void solve(int w, int h)
{
  VV b(h + 1, V(w));
  VV a(h, V(w + 1));

  REP(i, w)
  {
    b[0][i] = 1;
    b[h][i] = 1;
  }

  REP(i, 2 * h - 1)
  {
    if (i % 2 == 0)
    {
      a[i / 2][0] = 1;
      REP2(j, 1, w)
      {
        cin >> a[i / 2][j];
      }
      a[i / 2][w] = 1;
    }
    else
    {
      REP(j, w)
      {
        cin >> b[i / 2 + 1][j];
      }
    }
  }

  P d[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

  queue<pair<P, int>> q;
  int ans = -1;
  q.push(make_pair(make_pair(0, 0), 0));
  VV jd(h, V(w));
  while (q.size() != 0)
  {
    P ptr = q.front().first;
    int num = q.front().second;
    q.pop();

    jd[ptr.first][ptr.second] = 1;

    if (ptr.first == h - 1 && ptr.second == w - 1)
    {
      ans = num;
      break;
    }

    REP(i, 4)
    {
      P next = make_pair(ptr.first + d[i].first, ptr.second + d[i].second);
      if (0 <= next.first && next.first < h && 0 <= next.second && next.second < w)
      {
        if (jd[next.first][next.second] == 0)
        {
          if (i == 0 && b[ptr.first + 1][ptr.second] == 0)
          {
            q.push(make_pair(next, num + 1));
          }
          else if (i == 1 && b[ptr.first][ptr.second] == 0)
          {
            q.push(make_pair(next, num + 1));
          }
          else if (i == 2 && a[ptr.first][ptr.second + 1] == 0)
          {
            q.push(make_pair(next, num + 1));
          }
          else if (i == 3 && a[ptr.first][ptr.second] == 0)
          {
            q.push(make_pair(next, num + 1));
          }
        }
      }
    }
  }

  if (ans == -1)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << ans + 1 << endl;
  }
}

int main()
{
  while (1)
  {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0)
    {
      break;
    }
    solve(w, h);
  }

  return 0;
}