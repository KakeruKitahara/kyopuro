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

int main()
{
  S s;
  cin >> s;
  set<int> ans;
  V seed, abso;
  REP(i, s.size())
  {
    if (s[i] == 'o')
    {
      seed.push_back(i);
      abso.push_back(i);
    }
    if (s[i] == '?')
    {
      seed.push_back(i);
    }
  }
  for (int a : seed)
  {
    for (int b : seed)
    {
      for (int c : seed)
      {
        for (int d : seed)
        {
          ans.insert(a * 1000 + b * 100 + c * 10 + d);
        }
      }
    }
  }
  int cnt = 0;

  for (int itr : ans)
  {
    V abso2 = abso;
    int tmp2 = itr;
    REP(i, 4)
    {
      REP(j, abso2.size())
      {
        if (tmp2 % 10 == abso2[j])
        {
          abso2.erase(abso2.begin() + j);
          break;
        }
      }
      tmp2 /= 10;
    }
    if (abso2.size() == 0)
    {
      cnt++;
    }
  }

  cout << cnt << endl;
}