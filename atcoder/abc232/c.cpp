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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n, m, flg;
  cin >> n >> m;
  V a(m), b(m), c(m), d(m);
  VV ta(n, V(n)), ao(n, V(n));
  REP(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    ta[a[i]][b[i]]++;
    ta[b[i]][a[i]]++;
  }
  REP(i, m)
  {
    cin >> c[i] >> d[i];
    c[i]--;
    d[i]--;
    ao[c[i]][d[i]]++;
    ao[d[i]][c[i]]++;
  }

  V p;
  REP(i, n)
  {
    p.push_back(i);
  }

  do
  {
    VV ta2(n, V(n));
    flg = 0;
    V cc = {2, 1, 0, 3};

    REP(j, m)
    {
      ta2[p[a[j]]][p[b[j]]] = ta[a[j]][b[j]];
      ta2[p[b[j]]][p[a[j]]] = ta[b[j]][a[j]];
    }
    REP(j, n)
    {
      REP(k, n)
      {
        if (ta2[j][k] != ao[j][k])
        {
          flg = 1;
        }
      }
    }
    if (flg == 0)
    {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << "No" << endl;

  return 0;
}