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
  V a(n + 1);
  REP2(i, 1, n + 1)
  {
    cin >> a[i];
  }

  V ans;
  REPR(i, n + 1)
  {
    if (i == 0)
      break;

    ll sum = 0;
    int cnt = 0;
    for (int j = i + i; j <= n; j += i)
    {
      sum += a[j];
      cnt++;
    }
    if (cnt == 0)
    {
      if (a[i] == 1)
      {
        ans.push_back(i);
      }
      continue;
    }
    if (sum % 2 != a[i])
    {
      a[i] = 1;
    }
    else
    {
      a[i] = 0;
    }

    if (a[i] == 1)
    {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  REP(i, ans.size())
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}