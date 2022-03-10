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

int main()
{

  int n;
  cin >> n;
  V c(3);
  REP(i, 3)
  {
    cin >> c[i];
  }

  sort(c.rbegin(), c.rend());

  map<int, int> mp1, mp2, mp3;
  int am = n / c[0];
  REP(i, min(am + 1, 9999))
  {
    mp1[i * c[0]] = i;
  }

  for (pair<int, int> m : mp1)
  {
    if (n != m.first)
    {
      int bm = (n - m.first) / c[1];
      REP(j, min(bm + 1, 9999))
      {
        if (mp2.count(m.first - j * c[1]) == 1)
          mp2[m.first + j * c[1]] = min(m.second + j, mp2[m.first + j * c[1]]);
        else
          mp2[m.first + j * c[1]] = m.second + j;
      }
    }
  }

  for (pair<int, int> m : mp2)
  {
    if (n != m.first)
    {
      int cm = (n - m.first) / c[2];
      REP(j, min(cm + 1, 9999))
      {
        if (mp3.count(m.first - j * c[2]) == 1)
          mp3[m.first + j * c[2]] = min(m.second + j, mp2[m.first + j * c[2]]);
        else
          mp3[m.first + j * c[2]] = m.second + j;
      }
    }
  }

  cout << mp3[n] << endl;
  return 0;
}