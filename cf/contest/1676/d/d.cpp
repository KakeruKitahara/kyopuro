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
  vector<VV> mp(t);
  VV rsum(t);
  VV csum(t);
  REP(i, t)
  {
    int n, m;
    cin >> n >> m;
    mp[i].resize(n);

    REP(j, n)
    {
      mp[i][j].resize(m);
      REP(k, m)
      {
        cin >> mp[i][j][k];
      }
    }
  }

  REP(i, t)
  {

    for (int j = 0; j != mp[i].size() - 1; j++)
    {
      int k = mp[i].size() - j - 1;
      int l = 0;
      rsum[i].push_back(0);
      while (1)
      {
        rsum[i].back() += mp[i][k][l];
        if (k == mp[i].size() - 1 || l == mp[i][j].size() - 1)
        {
          break;
        }
        k++;
        l++;
      }
    }
    for (int j = 0; j != mp[i][j].size() - 1; j++)
    {
      int k = 0;
      int l = j;
      rsum[i].push_back(0);
      while (1)
      {
        rsum[i].back() += mp[i][k][l];
        if (k == mp[i].size() - 1 || l == mp[i][j].size() - 1)
        {
          break;
        }
        k++;
        l++;
      }
    }
    rsum[i].push_back(mp[i][0][mp[i][0].size() - 1]);

    for (int j = 0; j != mp[i].size() - 1; j++)
    {
      int k = mp[i].size() - j - 1;
      int l = 0;
      csum[i].push_back(0);
      while (1)
      {
        csum[i].back() += mp[i][k][l];
        if (k == 0 || l == mp[i][j].size() - 1)
        {
          break;
        }
        k--;
        l++;
      }
    }
    for (int j = 0; j != mp[i][j].size() - 1; j++)
    {
      int k = mp[i].size() - 1;
      int l = j;
      csum[i].push_back(0);
      while (1)
      {
        csum[i].back() += mp[i][k][l];
        if (k == 0 || l == mp[i][j].size() - 1)
        {
          break;
        }
        k--;
        l++;
      }
    }
    csum[i].push_back(mp[i][mp[i].size() - 1][mp[i][0].size() - 1]);
    int maxr = -1, maxc = -1;

    int mri, mci;
    REP(j, rsum[i].size())
    {
      if (maxr < rsum[i][j])
      {
        maxr = rsum[i][j];
      }
      = max(rsum[i][j], maxr);
      mri = j;
    }
    REP(j, csum[i].size())
    {
      maxc = max(csum[i][j], maxc);
      mci = j;
    }

    int jjx, jjy;
    int kkx, kky;
    if (mri < mp[i].size() - 1)
    {
      jjy = mp[i].size() - 1 - mri;
      jjx = 0;
    }
    else
    {
      jjy = 0;
      jjx = mri - (mp[i].size() - 1);
    }

    if (mci < mp[i].size() - 1)
    {
      kky = mp[i].size() - 1 - mci;
      kkx = 0;
    }
    else
    {
      kky = 0;
      kkx = mci - (mp[i].size() - 1);
    }

    while (1)
    {
      kky--;
      kkx++;
      jjx++;
      jjy++;
      if (kkx == jjx && kky == kkx)
      {
        break;
      }
    }

    cout << maxr + maxc - mp[i][jjy][jjx] << endl;
  }

  return 0;
}