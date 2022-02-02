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
  S s[4];
  REP(i, 4)
  {
    cin >> s[i];
  }

  S a[4] = {"H", "2B", "3B", "HR"};

  int flag[4] = {};
  REP(i, 4)
  {
    REP(j, 4)
    {
      if (s[i] == a[j])
        flag[j]++;
    }
  }

  REP(i, 4)
  {
    if (flag[i] == 0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}