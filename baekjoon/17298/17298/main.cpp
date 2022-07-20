//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n, a[1001000];
ll answer[1001000];
vector<ll> v;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  for(ll i = n; i >= 1; i--) {
    if(v.empty()) {
      answer[i] = -1;
      v.push_back(a[i]);
    } else if(v.back() > a[i]) {
      answer[i] = v.back();
      v.push_back(a[i]);
    } else {
      while(!v.empty() && v.back() <= a[i]) {
        v.pop_back();
      }
      if(v.empty()) {
        answer[i] = -1;
        v.push_back(a[i]);
      } else {
        answer[i] = v.back();
        v.push_back(a[i]);
      }
    }
  }
  
  for(ll i = 1; i <= n; i++){
    cout << answer[i] << ' ';
  }
  cout << '\n';
  
  return 0;
}

