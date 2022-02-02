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
VV e;
V t;

void dfs(int ptr)
{
  cout << ptr << " ";

  int cnt = 0;

  t[ptr] = 1;

  int p;

  REP(i, e[ptr].size())
  {
    if (t[e[ptr][i]] == 0)
    {
      cnt++;
      dfs(e[ptr][i]);
      cout << ptr << " ";
    }
  }

  return;
}

int main()
{
  int n;
  cin >> n;
  e.resize(n + 1);
  t.resize(n + 1);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  REP(i, e.size())
  {
    sort(e[i].begin(), e[i].end());
  }

  dfs(1);
  cout << endl;
  return 0;
}