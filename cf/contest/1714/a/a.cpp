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
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;

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

void solve()
{
  int n, h, m;
  cin >> n >> h >> m;
  VP hm(n);
  REP(i, n)
  {
    cin >> hm[i].first >> hm[i].second;
  }

  sort(hm.begin(), hm.end());

  auto p = lower_bound(hm.begin(), hm.end(), make_pair(h, m));
  if (p == hm.end())
  {
    int ah = hm.begin()->first + 24 - h;
    int m2 = hm.begin()->second - m;
    int am;
    if (m2 < 0)
    {
      am = 60 + m2;
      ah--;
    }
    else
    {
      am = m2;
    }

    cout << ah << " " << am << endl;
  }
  else
  {
    int ah = p->first - h;
    int m2 = p->second - m;
    int am;
    if (m2 < 0)
    {
      am = 60 + m2;
      ah--;
    }
    else
    {
      am = m2;
    }
    cout << ah << " " << am << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}