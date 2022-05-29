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

int main()
{
  int n, m;
  cin >> n >> m;
  S s;
  cin >> s;
  vector<pair<int, char>> q(m);
  REP(i, m)
  {
    cin >> q[i].first >> q[i].second;
    q[i].first--;
  }

  set<int> ans;

  REP(i, n - 2)
  {
    if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
    {
      ans.insert(i);
    }
  }

  REP(i, m)
  {
    int ind = q[i].first;
    if (s[ind] == 'a')
    {
      ans.erase(ind);
    }
    else if (s[ind] == 'b')
    {
      ans.erase(ind - 1);
    }
    else
    {
      ans.erase(ind - 2);
    }

    s[ind] = q[i].second;

    if (s[ind] == 'a')
    {
      if (ind == n - 1 || ind == n - 2)
      {
        cout << ans.size() << endl;
        continue;
      }

      if (s[ind + 1] == 'b' && s[ind + 2] == 'c')
      {
        ans.insert(ind);
      }
    }
    else if (s[ind] == 'b')
    {
      if (ind == n - 1 || ind == 0)
      {
        cout << ans.size() << endl;
        continue;
      }
      if (s[ind - 1] == 'a' && s[ind + 1] == 'c')
      {
        ans.insert(ind - 1);
      }
    }
    else
    {
      if (ind == 1 || ind == 0)
      {
        cout << ans.size() << endl;
        continue;
      }
      if (s[ind - 2] == 'a' && s[ind - 1] == 'b')
      {
        ans.insert(ind - 2);
      }
    }
    cout << ans.size() << endl;
  }

  return 0;
}