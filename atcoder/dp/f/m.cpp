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
  S s, t;
  cin >> s >> t;

  VV dp(s.size(), V(t.size()));

  if (s[0] == t[0])
  {
    dp[0][0] = 1;
  }

  REP2(i, 1, t.size())
  {
    if (s[0] == t[i])
    {
      dp[0][i] = 1;
    }
    else
    {
      dp[0][i] = dp[0][i - 1];
    }
  }

  REP2(i, 1, s.size())
  {
    if (s[i] == t[0])
    {
      dp[i][0] = 1;
    }
    else
    {
      dp[i][0] = dp[i - 1][0];
    }
  }

  REP2(i, 1, s.size())
  {
    REP2(j, 1, t.size())
    {
      if (s[i] == t[j])
      {
        dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1] + 1));
      }
      else
      {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  int k = t.size() - 1;
  S ans;
  int i = s.size() - 1, j = t.size() - 1;
  while (dp[i][j] != 0)
  {
    if (i == 0 && j == 0)
    {
      if (s[0] == t[0])
      {
        ans.push_back(s[0]);
      }
      break;
    }
    else if (i == 0)
    {
      if (dp[0][j] == dp[0][j - 1] + 1)
      {
        ans.push_back(s[0]);
      }
      j = j - 1;
      continue;
    }
    else if (j == 0)
    {
      if (dp[i][0] == dp[i - 1][0] + 1)
      {
        ans.push_back(t[0]);
      }

      i = i - 1;
      continue;
    }
    if (dp[i][j] == dp[i - 1][j - 1] + 1 && s[i] == t[j])
    {
      ans.push_back(s[i]);
      j = j - 1;
      i = i - 1;
    }
    else if (0 < j && dp[i][j] == dp[i][j - 1])
    {
      j = j - 1;
    }
    else if (0 < i && dp[i][j] == dp[i - 1][j])
    {
      i = i - 1;
    }
  }

  REPR(i, ans.size())
  {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
