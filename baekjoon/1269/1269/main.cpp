//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

ll n, m, k;
set<ll> a, b, common, answer;


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) {
    cin >> k;
    a.insert(k);
  }
  
  for(ll i = 1; i <= m; i++) {
    cin >> k;
    if(a.find(k) == a.end()) {
      answer.insert(k);
    } else{
      common.insert(k);
    }
  }
  for(auto iter = a.begin(); iter != a.end(); iter++) {
    if(common.find(*iter) == common.end()) {
      answer.insert(*iter);
    }
  }
  cout << answer.size() << '\n';
  
  return 0;
}

