#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  S s;
  cin >> s;

  deque<char> t;

  int flag = 0;
  REP(i, s.size())
  {
    if (s[i] == 'R')
    {
      if (flag == 1)
      {
        flag = 0;
      }
      else
      {
        flag = 1;
      }
    }
    else
    {
      if (t.empty())
      {
        if (flag == 0)
          t.push_back(s[i]);
        else
          t.push_front(s[i]);
      }
      else
      {
        if (flag == 0)
        {
          t.push_back(s[i]);
          if (t[t.size() - 1] == t[t.size() - 2])
          {
            t.pop_back();
            t.pop_back();
          }
        }
        else
        {
          t.push_front(s[i]);
          if (t[0] == t[1])
          {
            t.pop_front();
            t.pop_front();
          }
        }
      }
    }
  }
  if (flag == 1)
  {
    reverse(t.begin(), t.end());
  }
  for (char x : t)
  {
    cout << x;
  }
  cout << endl;
}