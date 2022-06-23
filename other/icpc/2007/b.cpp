#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;

void solve(int n, int m)
{
  int r, q;
  cin >> r;

  VV aaa;
  REP(i, r)
  {
    V tnms(4);
    cin >> tnms[0] >> tnms[2] >> tnms[1] >> tnms[3];
    tnms[1]--;
    aaa.push_back(tnms);
  }

  sort(aaa.begin(), aaa.end());
  cin >> q;
  V te(q), ts(q), m3(q);
  REP(i, q)
  {
    cin >> ts[i] >> te[i] >> m3[i];
    m3[i]--;
  }

  VV a(m, V(2000));

  int k = 0, f = 0;
  REP2(i, 540, 1261)
  {
    if (i == 678)
    {
      cout << "";
    }
    REP(j, m)
    {
      a[j][i] = a[j][i - 1];
      while (f == 0 && aaa[k][1] == j && i == aaa[k][0])
      {
        if (aaa[k][3] == 1)
        {
          a[j][i]++;
        }
        else
        {
          a[j][i]--;
        }
        k++;
        if (k == r)
        {
          f = 1;
          break;
        }
      }
    }
  }

  REP(i, q)
  {
    int ans = 0;
    REP2(j, ts[i], te[i])
    {
      if (a[m3[i]][j] >= 1)
      {
        ans++;
      }
    }

    cout << ans << endl;
  }
}

int main()
{
  while (1)
  {
    int m, n;
    cin >> n >> m;
    if (0 == m && n == 0)
    {
      break;
    }
    solve(n, m);
  }

  return 0;
}