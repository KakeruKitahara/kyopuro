#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main(){
  int n;
  cin>> n;
  int x[n], l[n];
  REP(i, n){
    cin >> x[i] >> l[i];
  }

  pair<long int, long int> key[n];

  REP(i, n){
    key[i].second = x[i] - l[i];
    key[i].first = x[i] + l[i];
  }

  sort(key, key+n);

  int s = key[0].second;

  int ans = 0;
  REP(i, n){
    if(s <= key[i].second){
      s = key[i].first;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}