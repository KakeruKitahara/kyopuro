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
  V k(t);
  vector<S> s(t);
  REP(i, t)
  {
    int n;
    cin >> n >> k[i] >> s[i];
  }

  REP(i, t)
  {
    VV alp(26);
    V ord;

    REP(j, s[i].size())
    {
      alp[s[i][j] - 'a'].push_back(j);
      ord.push_back(s[i][j] - 'a');
    }

    int st = -1;
    V dis(26);

    REP(j, s[i].size())
    {
      if (st < ord[j])
      {
        if (k[i] <= ord[j])
        {
          dis[ord[j]] = ord[j];
          break;
        }
        else
        {
          k[i] -= ord[j];
          dis[ord[j]] = ord[j];
          st = ord[j];
        }
      }
    }

    VV anso(26);
    st = 0;
    REP(j, 26)
    {
      if (dis[j] != 0)
      {

        for (int l = j; max(st, j - dis[j]) <= l; l--)
        {
          REP(m, alp[l].size())
          {
            anso[j - dis[j]].push_back(alp[l][m]);
          }
        }
        st = j;
      }
    }

    REP2(j, st + 1, 26)
    {
      REP(m, alp[j].size())
      {
        anso[j].push_back(alp[j][m]);
      }
    }

    S ans;
    REP(j, s[i].size())
    {
      ans += '0';
    }
    REP(j, 26)
    {
      REP(l, anso[j].size())
      ans[anso[j][l]] = j + 'a';
    }
    cout << ans << endl;
  }

  return 0;
}