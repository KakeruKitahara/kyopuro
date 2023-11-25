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

string tobinary(int n)
{
  string r;
  while (n != 0)
  {
    r += (n % 2 == 0 ? "0" : "1");
    n /= 2;
  }
  return r;
}

int solution(vector<int> &a)
{

  int n = a.size();
  int maxl = -1;
  VS sa(n);
  REP(i, n)
  {
    sa[i] = tobinary(a[i]);
    int len = sa[i].size();
    chmax(maxl, len);
  }

  REP(i, n)
  {
    while (sa[i].size() != maxl)
    {
      sa[i].push_back('0');
    }
  }
  int ans = -1;
  REP(i, maxl)
  {
    int c = 0;
    REP(j, n)
    {
      if (sa[j][i] == '1')
      {
        c++;
      }
    }
    chmax(ans, c);
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