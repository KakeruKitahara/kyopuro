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
  V p(n);

  vector<pair<char, int>> ans;
  REP(i, n)
  {
    cin >> p[i];
  }
  int l = n - 1;
  queue<int> o;
  for (int i = 0; i < n - 1; i++)
  {
    if (o.size() == 2 && 2 < n)
    {
      if (p[1] > p[2])
      {
        swap(p[1], p[2]);
        ans.push_back(make_pair('B', 2));
        while (o.size() != 0)
        {
          o.pop();
        }
      }
    }
    while (o.size() != 0)
    {
      ans.push_back(make_pair('A', o.front()));
      o.pop();
    }

    for (int j = n - 1; j >= i + 1; j--)
    {

      if (o.size() == 2)
      {
        if (p[j + 1] > p[j + 2])
        {
          swap(p[j + 1], p[j + 2]);
          ans.push_back(make_pair('B',j + 2));
          while (o.size() != 0)
          {
            o.pop();
          }
        }
      }

      if (p[j] < p[j - 1])
      {
        swap(p[j], p[j - 1]);
        o.push(j);
      }
      else
      {
        while (o.size() != 0)
        {
          ans.push_back(make_pair('A', o.front()));
          o.pop();
        }
      }
    }
  }
  if (o.size() == 2 && 2 < n)
  {
    if (p[1] > p[2])
    {
      swap(p[1], p[2]);
      ans.push_back(make_pair('B', 2));
      while (o.size() != 0)
      {
        o.pop();
      }
    }
  }
  while (o.size() != 0)
  {
    ans.push_back(make_pair('A', o.front()));
    o.pop();
  }

  cout << ans.size() << endl;
  REP(i, ans.size())
  {
    cout << ans[i].first << " " << ans[i].second << endl;
  }

  return 0;
}