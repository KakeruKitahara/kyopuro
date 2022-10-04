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

int c, k;
V num;

void dfs(int s)
{
  num[s] = num[s - 1] - 1;
  REP(i, 3)
  {
    if (s == num.size() - 1 && 0 <= num[s] && num[s] <= 9)
    {
      c++;
    }

    if (c == k)
    {
      REP(jj, num.size())
      {
        cout << num[jj];
      }
      cout << endl;
      exit(0);
    }

    if (0 <= num[s] && num[s] <= 9 && s != num.size() - 1)
    {
      dfs(s + 1);
    }

    num[s]++;
  }
}

int main()
{
  cin >> k;

  c = 0;
  num.push_back(0);
  REP2(i, 1, 10)
  {
    num[0] = i;
    c++;
    if (c == k)
    {
      cout << num[0] << endl;
      return 0;
    }
  }

  while (c < k)
  {
    num.push_back(0);
    REP2(i, 1, 10)
    {
      num[0] = i;
      dfs(1);
    }
  }

  return 0;
}