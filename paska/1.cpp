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

int lefts(V a, map<int, int> s, int p);
int nones(V a, map<int, int> s, int p, bool f);
int rights(V a, map<int, int> s, int p);

int lefts(V a, map<int, int> s, int p)
{
  int g = a.size() - 1;
  if (p == g)
  {
    int an = -1;
    for (auto k : s)
    {
      chmax(an, k.second);
    }
    return an;
  }
  s[a[p] + a[p - 1]]++;

  int ans = nones(a, s, p + 1, false);
  chmax(ans, rights(a, s, p + 1));
  return ans;
}

int nones(V a, map<int, int> s, int p, bool f)
{
  int g = a.size() - 1;
  if (p == g)
  {
    int an = -1;
    for (auto k : s)
    {
      chmax(an, k.second);
    }
    return an;
  }

  int ans = -1;
  if (f == true)
  {
    ans = lefts(a, s, p + 1);
    chmax(ans, nones(a, s, p + 1, false));
    chmax(ans, rights(a, s, p + 1));
  }
  else
  {
    chmax(ans, nones(a, s, p + 1, true));
    chmax(ans, rights(a, s, p + 1));
  }

  return ans;
}

int rights(V a, map<int, int> s, int p)
{
  int g = a.size() - 1;
  if (p == g)
  {
    int an = -1;
    for (auto k : s)
    {
      chmax(an, k.second);
    }
    return an;
  }
  s[a[p] + a[p + 1]]++;
  int ans = nones(a, s, p + 1, false);
  return ans;
}

int solution(V &a)
{
  map<int, int> score;
  int ans = max(nones(a, score, 0, false), rights(a, score, 0));
  return ans;
}

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  solution(a);
}
