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
  int t;
  cin >> t;
  vector<map<int, int>> mp(t);
  V h(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    cin >> h[i];
    REP(j, n)
    {
      int a;
      cin >> a;
      mp[i][a]++;
    }
  }

  REP(i, t)
  {
    V s;
    vector<P> p;
    P tp;
    int f = 0;
    for (auto it = mp[i].begin(); it != mp[i].end(); it++)
    {
      if (f == 0 && it->second >= h[i])
      {
        tp.first = it->first;
        f = 1;
      }
      else if (f == 1)
      {
        auto aa = --it;
        it++;
        if (it->first - 1 != aa->first)
        {
          tp.second = aa->first;
          p.push_back(tp);
          s.push_back(tp.second - tp.first);
          f = 0;
          if (f == 0 && it->second >= h[i])
          {
            tp.first = it->first;
            f = 1;
          }
        }
        else if (it->second < h[i])
        {
          tp.second = it->first - 1;
          p.push_back(tp);
          s.push_back(tp.second - tp.first);
          f = 0;
        }
      }
    }
    if (f == 1)
    {
      auto kkk = --mp[i].end();
      tp.second = kkk->first;
      p.push_back(tp);
      s.push_back(tp.second - tp.first);
    }
    int ms = -1, ind;
    REP(j, s.size())
    {
      if (ms < s[j])
      {
        ms = s[j];
        ind = j;
      }
    }
    if (s.size() == 0)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << p[ind].first << " " << p[ind].second << endl;
    }
  }

  return 0;
}