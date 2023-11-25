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

/* change function */
template <class X>
void chmin(X &a, X b) { a = min(a, b); }
template <class X>
void chmax(X &a, X b) { a = max(a, b); }

VV e;
set<int> ga;
V used;

P dfs(int p, int dis, int ply)
{
  P sumf = {0, 0};

  if (ga.count(p))
  {
    sumf.first += dis - ply;
    ply = dis;
    sumf.second = 1;
  }

  int en = e[p].size();
  REP(i, en)
  {
    P tmp;
    if (used[p] && sumf.second)
    {
      ply = dis;
    }
    tmp = dfs(e[p][i], dis + 1, ply);
    sumf.first += tmp.first;
    chmax(sumf.second, tmp.second);
    used[p] = 1;
  }

  return sumf;
}

int solution(vector<int> &t, vector<int> &a)
{
  int nt = t.size();
  int na = a.size();
  used.resize(nt);
  REP(i, na)
  {
    ga.insert(a[i]);
  }

  e.resize(nt);
  REP2(i, 1, nt)
  {
    e[t[i]].push_back(i);
  }

  P p = dfs(0, 1, 0);

  return p.first;
}

int main()
{
  int n, m;
  cin >> n >> m;
  V a(m);
  V t(n);
  REP(i, n)
  {
    cin >> t[i];
  }

  REP(i, m)
  {
    cin >> a[i];
  }

  cout << solution(t, a) << endl;
}