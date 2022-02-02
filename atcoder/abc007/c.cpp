/* 平面マスを用いる問題の時, 座標(x, y)は配列だとy行x列なのでa[y][x]と逆になるので注意. 座標の数え方 <-> 行列の数え方 */
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000
#define P pair<int, int>
using namespace std;

int dbs(char c[50][50], int v[50][50], P ptr, P goal)
{
  P w[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
  queue<P> next;
  queue<int> print;
  int tmp;
  P p_tmp;
  next.push(make_pair(ptr.first, ptr.second));
  print.push(0);

  /* このプログラムは自身の４近傍が条件に満たしたら, 最短経路数を保管etcをしてpushするプログラムだが,
    for分の外で自身のみを最短経路数を保管etcとする場合. 4近傍の経路保管をwhileを4ループ回すので1ターンごとに4倍の計算量になりTLEなる */

  while (next.size() != 0)
  {
    p_tmp = next.front();
    tmp = print.front();
    next.pop();
    print.pop();
    rep(i, 4)
    {
      int x = p_tmp.first + w[i].first;
      int y = p_tmp.second + w[i].second;
      if (c[y][x] == '.')
      {
        v[y][x] = tmp + 1; // forの中で保管をする.
        c[y][x] = '#'; // 補完もする.
        if (y == goal.second && x == goal.first)
        {
          break; // 一番早く着いたのが最短経路数.
        }
        next.push(make_pair(x, y));
        print.push(tmp + 1);
      }
    }
  }
  return v[goal.second][goal.first];
}

int main()
{
  int x, y;
  P s, g;
  cin >> y >> x;
  cin >> s.second >> s.first;
  cin >> g.second >> g.first;
  s.first--;
  s.second--;
  g.first--;
  g.second--;

  char c[50][50];
  rep(i, y)
  {
    rep(j, x)
    {
      cin >> c[i][j];
    }
  }
  int v[50][50];
  rep(i, y)
  {
    rep(j, x)
    {
      v[y][x] = INF;
    }
  }
  cout << dbs(c, v, s, g) << "\n";
  return 0;
}