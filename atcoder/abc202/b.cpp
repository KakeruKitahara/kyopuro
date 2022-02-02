#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;

int main(){
  S a;
  cin >> a;

  REP(i, a.size()){
    if(a[i] == '6'){
      a[i] = '9';
    }
    else if (a[i] == '9')
    {
      a[i] = '6';
    }
  }
  reverse(a.begin(), a.end());

  cout << a << endl;
  return 0;

}