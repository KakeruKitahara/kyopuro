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

vector<VV> mp2;

bool dfs(P ptr, int m, int n, vector<P> rob, int k)
{

  REP(i, rob.size())
  {
    if ( rob[i].first == 0 && rob[i].second == 0)
    {
      rob[i].second = IINF;
    }
    else if (!(0 <= rob[i].first && rob[i].first < m && 0 <= rob[i].second && rob[i].second < n))
    {
      if (rob[i].second != IINF)
      {
        return false;
      }
    }
  }

  if (ptr.first == 0 && ptr.second == 0)
  {
    return true;
  }

  P w[4] = {make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1)};
  bool jd, res = false;
  REP(i, 4)
  {
    ptr.first += w[i].first;
    ptr.second += w[i].second;

    if (!(0 <= ptr.first && ptr.first < m && 0 <= ptr.second && ptr.second < n) || mp2[k][ptr.second][ptr.first] == 1)
    {
      ptr.first -= w[i].first;
      ptr.second -= w[i].second;

      continue;
    }

    REP(j, rob.size())
    {
      if (rob[j].second != IINF)
      {
        rob[j].first += w[i].first;
        rob[j].second += w[i].second;
      }
    }

    mp2[k][ptr.second - w[i].second][ptr.first - w[i].first] = 1;
    jd = dfs(ptr, m, n, rob, k);

    ptr.first -= w[i].first;
    ptr.second -= w[i].second;
    REP(j, rob.size())
    {
      if (rob[j].second != IINF)
      {
        rob[j].first -= w[i].first;
        rob[j].second -= w[i].second;
      }
    }

    if (jd == true)
    {
      res = true;
      break;
    }
  }

  return res;
}

int main()
{
  int t;
  cin >> t;
  vector<vector<S>> mp(t);

  mp2.resize(t);

  REP(i, t)
  {
    int n, m;
    cin >> n >> m;
    mp[i].resize(n);
    mp2[i].resize(n);
    REP(j, n)
    {
      mp2[i][j].resize(m);
      cin >> mp[i][j];
    }
  }

  REP(i, t)
  {
    vector<P> r;
    int to = -1;
    P toi;
    REP(j, mp[i].size())
    {
      REP(k, mp[i][j].size())
      {

        if (mp[i][j][k] == 'R')
        {
          r.push_back(make_pair(k, j));
          if (to < j + k)
          {
            to = j + k;
            toi = make_pair(k, j);
          }
        }
      }
    }
    int m = mp[i][0].size();
    int n = mp[i].size();

    bool ans = dfs(toi, m, n, r, i);
    if (ans == true)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}