#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> ob;
  string tmp;
  rep(i, n)
  {
    cin >> tmp;
    ob.push_back(tmp);
  }
  rep(i, n){
    reverse(ob[i].begin(), ob[i].end());
  }
  sort(ob.begin(), ob.end());
  rep(i, n){
    if(ob[i] + "!" == ob[i + 1]){
      for(auto p = ob[i].rbegin(); p != ob[i].rend(); p++){
        cout << *p;
      }
      return 0;
    }
  }
  cout << "satisfiable";
  return 0;
}
