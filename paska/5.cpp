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

vector<int> solution(int n)
{
  V ans;
  int usum = 0;
  int o = 1;
  while (n >= usum + o)
  {
    usum += o;
    ans.push_back(o);
    o += 2;
  }

  int d = n - usum;
  if ((ans.back() + d) % 2 == 1)
  {
    ans.back() += d;
  }
  else
  {
    int l = ans.back();
    ans.erase(ans.end() - 1);
    ans.back() += l + d;
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  V ans = solution(n);
  REP(i, ans.size())
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}