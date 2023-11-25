#include <bits/stdc++.h>
using namespace std;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;

template <typename T>
struct BIT
{
  int n;
  vector<T> bit[2];
  BIT(int n_) { init(n_); }
  void init(int n_)
  {
    n = n_ + 1;
    for (int p = 0; p < 2; p++)
      bit[p].assign(n, 0);
  }
  void add_sub(int p, int i, T x)
  {
    for (int idx = i; idx < n; idx += (idx & -idx))
    {
      bit[p][idx] += x;
    }
  }
  void add(int l, int r, T x)
  { // [l,r) に加算
    add_sub(0, l, -x * (l - 1));
    add_sub(0, r, x * (r - 1));
    add_sub(1, l, x);
    add_sub(1, r, -x);
  }
  T sum_sub(int p, int i)
  {
    T s(0);
    for (int idx = i; idx > 0; idx -= (idx & -idx))
    {
      s += bit[p][idx];
    }
    return s;
  }
  T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

int main()
{
  int n, m;
  cin >> n >> m;
  map<int, set<int>> pos;
  BIT<ll> ans(n);
  REP(i, n)
  {
    int a;
    cin >> a;
    pos[a].insert(i);
  }
  VP lr(m);

  REP(i, m)
  {
    cin >> lr[i].first >> lr[i].second;
  }

  REP(i, m)
  {
    REP2(j, lr[i].first, lr[i].second + 1)
    {
      auto it = pos.lower_bound(j);
      auto it2 = it;
      it2--;
      int costa = abs(it->first - j);
      int costb = abs(it2->first - j);

      if (it == pos.begin())
      {
        costb = IINF;
      }

      int cost = min(costa, costb);
      {
        map<int, set<int>> tmp;
        for (auto k : pos)
        {
          if (k.first <= j)
          {
            tmp[k.first + cost] = k.second;
          }
          else
          {
            if (tmp.count(k.first - cost))
            {
              for (auto l : k.second)
              {
                tmp[k.first - cost].insert(l);
              }
            }
            else
            {
              tmp[k.first - cost] = k.second;
            }
          }
        }

        pos = tmp;
      }

      auto itb = pos[j].rbegin();
      auto ita = pos[j].begin();
      ans.add(*ita + 1, *itb + 2, 1);

        V ans2(n);
  ans2[0] = ans.sum(1);
  REP2(i, 1, n)
  {
    ans2[i] = ans.sum(i + 1) - ans.sum(i);
  }
  REP(i, n)
  {
    cout << ans2[i] << " ";
  }
  cout << endl;


    }
  }

  V ans2(n);
  ans2[0] = ans.sum(1);
  REP2(i, 1, n)
  {
    ans2[i] = ans.sum(i + 1) - ans.sum(i);
  }
  REP(i, n)
  {
    cout << ans2[i] << " ";
  }
  cout << endl;

  return 0;
}
