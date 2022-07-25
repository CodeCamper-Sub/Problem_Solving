//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;

ll n, c, k;
vector<ll> x;
ll left_bound, right_bound, mid;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> c;
  for(ll i = 1; i <= n; i++) {
    cin >> k;
    x.push_back(k);
  }
  sort(x.begin(), x.end());
  left_bound = 0;
  right_bound = x[x.size()-1] - x[0];
  while(left_bound <= right_bound) {
    mid = (left_bound + right_bound) / 2;
    ll left_c = c;
    ll next = LONG_LONG_MIN;
    for(ll i = 0; i < x.size(); i++) {
      if(x[i] >= next) {
        next = x[i] + mid;
        left_c--;
      }
    }
    if(left_c <= 0) {
      left_bound = mid + 1;
    } else {
      right_bound = mid - 1;
    }
  }
  cout << right_bound << '\n';
  
  
  return 0;
}
