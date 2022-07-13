#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

/* pair operator */
template <class X>
pair<X, X> operator+(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first + ob2.first;
  res.second = ob1.second + ob2.second;
  return res;
}

template <class X>
pair<X, X> operator-(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first - ob2.first;
  res.second = ob1.second - ob2.second;
  return res;
}

template <class X>
pair<X, X> operator*(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first * ob2.first;
  res.second = ob1.second * ob2.second;
  return res;
}

template <class X>
pair<X, X> operator/(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first / ob2.first;
  res.second = ob1.second / ob2.second;
  return res;
}

int main()
{
  int n;
  cin >> n;
  VVP m(n);
  REP(i, n)
  {
    int t;
    cin >> t;
    m[i].resize(t);
    REP(j, t)
    {
      cin >> m[i][j].first >> m[i][j].second;
    }
  }
  map<ll, VP> mp;
  REP(i, n)
  {
    REP(j, m[i].size())
    {
      mp[m[i][j].first].push_back(make_pair(m[i][j].second, i));
    }
  }

  for (pair<int, VP> aa : mp)
  {
    sort(aa.second.rbegin(), aa.second.rend());
  }

  map<int, int> maxs;
  for (pair<int, VP> aa : mp)
  {
    maxs[aa.first] = aa.second[0].first;
  }

  set<map<int, int>> ans;
  map<int, int> tm = maxs;
  REP(i, n)
  {
    VP re;
    REP(j, m[i].size())
    {
      if (mp[m[i][j].first][0].first == m[i][j].second)
      {
        tm[m[i][j].first] = mp[m[i][j].first][1].first;
        re.push_back(make_pair(m[i][j].first, mp[m[i][j].first][0].first));
      }
    }

    ans.insert(tm);

    REP(i, re.size())
    {
      tm[re[i].first] = re[i].second;
    }
  }
  cout << ans.size() << endl;

  return 0;
}