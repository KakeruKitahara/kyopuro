#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, a, n) for (int i = a; n <= i; i--) // batu
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  S s, t;
  int flag = 100, cnt;
  cin >> s >> t;

  if (s.size() < t.size())
  {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  REPR(i, s.size() - t.size() + 1)
  {
    cnt = 0;
    REP(j, t.size())
    {
      if (s[i + j] == '?' || s[i + j] == t[j])
        cnt++;
    }
    if (cnt == t.size())
    {
      flag = i;
      break;
    }
  }

  if (flag == 100)
  {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  else
  {
    REP(i, t.size())
    {
      s[flag + i] = t[i];
    }
  }

  REP(i, s.size())
  {
    if (s[i] == '?')
      s[i] = 'a';
  }

  cout << s << endl;
  return 0;
}