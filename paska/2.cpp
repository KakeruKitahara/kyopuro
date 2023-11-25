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

vector<int> solution(vector<int> &x, vector<int> &y)
{

  V ans;
  int g = x.size();
  if (g <= 2)
  {
    return ans;
  }
  vector<pair<P, int>> xy(g);
  REP(i, g)
  {
    xy[i] = {{x[i], y[i]}, i};
  }

  sort(xy.begin(), xy.end());
  pair<P, int> zero = xy[0];

  vector<pair<ll, pair<P, int>>> disvp(g - 1);

  REP2(i, 1, g)
  {
    ll dis = (xy[i].first.first - zero.first.first) * (xy[i].first.first - zero.first.first) + (xy[i].first.second - zero.first.second) * (xy[i].first.second - zero.first.second);
    disvp[i - 1] = {dis, xy[i]};
  }
  sort(disvp.begin(), disvp.end());
  pair<P, int> one = disvp[0].second;
  pair<P, int> anst = {{-1, -1}, -1};
  REP2(i, 1, g - 1)
  {
    pair<P, int> two = disvp[i].second;

    P sone = {one.first.first - zero.first.first, one.first.second - zero.first.second};
    P stwo = {two.first.first - zero.first.first, two.first.second - zero.first.second};

    if (stwo.first * sone.second != stwo.second * sone.first)
    {
      anst = two;
      break;
    }
  }

  if (anst.second == -1)
  {
    return ans;
  }

  ans.push_back(zero.second);
  ans.push_back(one.second);
  ans.push_back(anst.second);

  return ans;
}

int main()
{
  int n;
  cin >> n;
  V x(n), y(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }
  V ans = solution(x, y);
  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
