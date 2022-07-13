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
  VS s(3);
  V a(50);
  unordered_map<char, int> mp;
  REP(i, 3)
  {
    cin >> s[i];
    REP(j, s[i].size())
    {
      a[s[i][j] - 'a']++;
      mp[s[i][j]] = -1;
    }
  }
  int c = 0;
  REP(i, 50)
  {
    if (a[i] > 0)
    {
      c++;
    }
  }

  if (c > 10)
  {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }

  V num(10);
  REP(i, 10)
  {
    num[i] = i;
  }

  do
  {
    int p = 0;
    for (auto &b : mp)
    {
      b.second = num[p];
      p++;
    }
    Vl nn(3);
    REP(i, 3)
    {
      REP(j, s[i].size())
      {
        for (pair<char, int> b : mp)
        {
          if (s[i][j] == b.first)
          {
            if (j == 0 && b.second == 0)
            {
              nn[i] = 0;
              j = s[i].size() - 1;
              break;
            }
            nn[i] += b.second;
            break;
          }
        }
        if (j != s[i].size() - 1)
          nn[i] *= 10;
      }
    }

    if (nn[0] + nn[1] == nn[2] && (nn[0] != 0 && nn[1] != 0 && nn[2] != 0))
    {
      REP(i, 3)
      {
        cout << nn[i] << endl;
      }
      return 0;
    }
  } while (next_permutation(num.begin(), num.end()));
  cout << "UNSOLVABLE" << endl;
  return 0;
}