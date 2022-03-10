#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n ; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;
 

// 1-indexedなので注意。
struct BIT
{
private:
  vector<int> bit;
  int N;

public:
  BIT(int size)
  {
    N = size;
    bit.resize(N + 1);
  }

  // 一点更新です
  void add(int a, int w)
  {
    for (int x = a; x <= N; x += x & -x)
      bit[x] += w;
  }

  // 1~Nまでの和を求める。
  int sum(int a)
  {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

// ====================================================================

int main()
{
  int n;
  cin >> n;
  vector<int> v(n - 2), v(n) ;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  REP(i, n -2){

  }

  ll ans = 0;
  BIT b(n); // これまでの数字がどんな風になってるのかをメモる為のBIT
  for (int i = 0; i < n; i++)
  {
    ans += i - b.sum(v[i]); // BITの総和 - 自分より左側 ＝ 自分より右側
    b.add(v[i], 1);         // 自分の位置に1を足す(ダジャレではないです)
  }

  if(ans % 2 == 0){
    if()
  }
}
