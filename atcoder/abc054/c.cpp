#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int m, n;
  P ePair[28];
  cin >> n >> m;
  rep(i, m)
  {
    cin >> ePair[i].first >> ePair[i].second;
  }

  do
  {
    rep(i, n - 1){
      ptr = v[i]
      rep(j, n - 1){
        if(ePair[i].first == v[i] && ePair[].second == j){
          flag = 1;
          break;
        }
      }
    }
  } while (std::next_permutation(v.begin() + 1, v.end()));
}