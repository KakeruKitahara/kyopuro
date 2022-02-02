#include <bits/stdc++.h>
using namespace std;

bool dfs(char c[500][501], pair<int, int> walk[4], int ptr_row, int ptr_col)
{
  bool check = false;
  c[ptr_row][ptr_col] = '#';
  for (int i = 0; i < 4; i++)
  {
    if (c[ptr_row + walk[i].first][ptr_col + walk[i].second] == 'g')
    {
      return true;
    }
    if (c[ptr_row + walk[i].first][ptr_col + walk[i].second] == '.')
    {
      if(check == false){
        check = dfs(c, walk, ptr_row + walk[i].first, ptr_col + walk[i].second);
      }
    }
  }
  if (check == true)
    return true;
  return false;
}

int main()
{
  int h, w;
  scanf("%d", &h);
  scanf("%d", &w);
  char c[500][501];
  for (int i = 0; i < h; i++)
  {
    scanf("%s", c[i]);
  }

  pair<int, int> walk[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

  int ptr_row, ptr_col;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if ('s' == c[i][j])
      {
        ptr_row = i;
        ptr_col = j;
      }
    }
  }

  bool key = dfs(c, walk, ptr_row, ptr_col);
  if (key == true)
  {
    printf("Yes");
  }
  else
  {
    printf("No");
  }
  return 0;
}
