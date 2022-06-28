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

bool aa(tuple<int, int, int> l, tuple<int, int, int> r)
{
  if (get<0>(l) == get<0>(r) && get<1>(l) == get<1>(r))
    return get<2>(l) > get<2>(r);
  else if (get<0>(l) == get<0>(r))
    return get<1>(l) < get<1>(r);
  else
    return get<0>(l) > get<0>(r);
}

void solve(int m, int t, int p, int r)
{
  V m2(r), t2(r), p2(r), j2(r);
  REP(i, r)
  {
    cin >> m2[i] >> t2[i] >> p2[i] >> j2[i];
    p2[i]--;
    t2[i]--;
  }

  vector<tuple<int, int, int>> mon(t);
  VV sum(t, V(p));
  REP(i, r)
  {
    if (j2[i] == 1)
    {
      sum[t2[i]][p2[i]] += 20;
    }
    else
    {
      get<0>(mon[t2[i]])++;
      get<1>(mon[t2[i]]) += sum[t2[i]][p2[i]] + m2[i];
    }
  }

  REP(i, t)
  {
    get<2>(mon[i]) = i + 1;
  }

  sort(mon.begin(), mon.end(), aa);


  REP(i, t)
  {
    if (i == t - 1)
    {
      cout << get<2>(mon[i]) << endl;
    }
    else
    {
      if (get<0>(mon[i]) == get<0>(mon[i + 1]) && get<1>(mon[i]) == get<1>(mon[i + 1]))
      {
        cout << get<2>(mon[i]) << "=";
      }
      else
      {
        cout << get<2>(mon[i]) << ",";
      }
    }
  }
}

int main()
{
  while (1)
  {
    int m, t, p, r;
    cin >> m >> t >> p >> r;
    if (m == 0 && t == 0 && p == 0 && r == 0)
    {
      break;
    }
    solve(m, t, p, r);
  }

  return 0;
}