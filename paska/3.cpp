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

int solution(vector<int> &a)
{
  V comp;
  int n = a.size();
  comp.push_back(a[0]);
  REP2(i, 1, n)
  {
    if (comp.back() == a[i])
    {
      continue;
    }
    comp.push_back(a[i]);
  }

  int cn = comp.size();
  int ans = 0;
  REP(i, cn)
  {
    if (i == cn - 1 || i == 0)
    {
      ans++;
    }
    else
    {
      if (comp[i - 1] < comp[i] && comp[i] > comp[i + 1])
      {
        ans++;
      }
      else if (comp[i - 1] > comp[i] && comp[i] < comp[i + 1])
      {
        ans++;
      }
    }
  }

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
  cout << solution(a) << endl;
}