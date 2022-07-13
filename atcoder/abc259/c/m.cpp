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
  vector<pair<char, int>> a, b;
  if (s.size() > t.size())
  {
    cout << "No" << endl;
    return 0;
  }
  pair<char, int> ta;
  ta = make_pair(s[0], 1);
  REP(i, s.size() - 1)
  {
    if (s[i] == s[i + 1])
    {
      ta.second++;
    }
    else
    {
      a.push_back(ta);
      ta = make_pair(s[i + 1], 1);
    }
  }
  a.push_back(ta);
  ta = make_pair(t[0], 1);
  REP(i, t.size() - 1)
  {
    if (t[i] == t[i + 1])
    {
      ta.second++;
    }
    else
    {
      b.push_back(ta);
      ta = make_pair(t[i + 1], 1);
    }
  }
  b.push_back(ta);

  if (a.size() != b.size())
  {
    cout << "No" << endl;
    return 0;
  }
  REP(i, a.size())
  {
    if (a[i].first != b[i].first)
    {
      cout << "No" << endl;
      return 0;
    }
    else
    {
      if (a[i].second > b[i].second)
      {
        cout << "No" << endl;
        return 0;
      }
      if (a[i].second < b[i].second && a[i].second < 2)
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}