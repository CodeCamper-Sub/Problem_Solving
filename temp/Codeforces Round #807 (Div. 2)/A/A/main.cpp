//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll tt, n, x, h;

void testcase() {
  vector<ll> height;
  cin >> n >> x;
  for(ll i = 1; i <= 2*n; i++) {
    cin >> h;
    height.push_back(h);
  }
  sort(height.begin(), height.end());
  for(ll i = 0; i + n < height.size(); i++) {
    if(height[i+n] - height[i] < x) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> tt;
  while(tt--) {
    testcase();
  }
  
  return 0;
}


