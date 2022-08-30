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
  S s;
  cin >> s;

  deque<char> ans;

  REP(i, s.size())
  {
    ans.push_back(s[i]);
  }

  int q;
  cin >> q;
  vector<tuple<int, int, char>> qu(q);
  REP(i, q)
  {
    cin >> get<0>(qu[i]);
    if (get<0>(qu[i]) == 2)
    {
      cin >> get<1>(qu[i]) >> get<2>(qu[i]);
    }
  }
  int f = 0;
  REP(i, q)
  {
    if (get<0>(qu[i]) == 1)
    {
      f = (f + 1) % 2;
    }
    else
    {
      if (f == 0)
      {
        if (get<1>(qu[i]) == 1)
        {
          ans.push_front(get<2>(qu[i]));
        }
        else
        {
          ans.push_back(get<2>(qu[i]));
        }
      }
      else
      {
        if (get<1>(qu[i]) == 2)
        {
          ans.push_front(get<2>(qu[i]));
        }
        else
        {
          ans.push_back(get<2>(qu[i]));
        }
      }
    }
  }

  if (f == 0)
  {
    REP(i, ans.size())
    {
      cout << ans[i];
    }
  }
  else
  {
    REPR(i, ans.size())
    {
      cout << ans[i];
    }
  }
  cout << endl;
  return 0;
}