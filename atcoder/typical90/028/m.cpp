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

int main()
{
  int n;
  vector<pair<int, int>> r(n), l(n), tmp, ans;
  vector<vector<pair<int, int>>> rect;
  REP(i, n)
  {
    cin >> l[i].first >> l[i].second >> r[i].first >> r[i].second;
    tmp.push_back(l[i]);
    tmp.push_back(make_pair(r[i].first, l[i].second));
    tmp.push_back(r[i]);
    tmp.push_back(make_pair(l[i].first, r[i].second));
    rect.push_back(tmp);
  }

  REP(i, n)
  {
    int f1 = 0, f2 = 0;
    int pattern1 = 0, pattern2 = 0;
    if (rect[i][0].first < ans[0].first && ans[0].first < rect[i][1].first)
      f1 = 1;
    if (rect[i][0].first < ans[1].first && ans[1].first < rect[i][1].first)
      f2 = 1;
    if (f1 == 1 && f2 == 1)
      pattern1 = 1;
    else if (f1 == 1)
      pattern1 = 2;
    else if (f2 == 1)
      pattern1 = 3;
    else if (rect[i][0].first < ans[0].first && ans[1].first < rect[i][1].first)
      pattern1 = 4;
    f1 = f2 = 0;
    if (rect[i][0].second < ans[0].second && ans[0].second < rect[i][1].second)
      f1 = 1;
    if (rect[i][0].second < ans[1].second && ans[1].second < rect[i][1].second)
      f2 = 1;
    if (f1 == 1 && f2 == 1)
      pattern2 = 1;
    else if (f1 == 1)
      pattern2 = 2;
    else if (f2 == 1)
      pattern2 = 3;
    else if (rect[i][0].second < ans[0].second && ans[1].second < rect[i][1].second)
      pattern2 = 4;

    if (pattern1 == 1 && pattern2 == 1)
    {
    }
    if (pattern1 == 1 && pattern2 == 2)
    {
      ans[0].first = rect[0].first;
      ans[1].first = rect[1].first;
      ans[0].second = rect[0].first;
    }
  }
}