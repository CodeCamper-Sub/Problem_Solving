//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, k;
ll left_bound, right_bound, mid, cnt;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  left_bound = 1;
  right_bound = n * n;
  while(left_bound <= right_bound) {
    mid = (left_bound + right_bound) / 2;
    cnt = 0;
    for(ll i = 1; i <= n; i++) {
      cnt += min(mid / i, n);
    }
    if(cnt >= k) {
      right_bound = mid - 1;
    } else {
      left_bound = mid + 1;
    }
  }
  cout << left_bound << '\n';
  
  
  
  return 0;
}

