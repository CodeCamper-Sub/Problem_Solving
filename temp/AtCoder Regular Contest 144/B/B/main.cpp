//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, a, b, seq[300300], maximum, remainer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  maximum = LONG_LONG_MIN;
  cin >> n >> a >> b;
  for(ll i = 1; i <= n; i++) {
    cin >> seq[i];
    maximum = max(maximum, seq[i]);
  }

  ll left_bound = 1;
  ll right_bound = maximum;
  while(left_bound <= right_bound) {
    ll mid = (left_bound + right_bound) / 2;
    remainer = 0;
    for(ll i = 1; i <= n; i++) {
      if(seq[i] > mid) {
        remainer += (seq[i]-mid) / b;
      } else {
        if((mid - seq[i]) % a) {
          remainer -= (mid-seq[i]) / a + 1;
        } else {
          remainer -= (mid-seq[i]) / a;
        }
      }
    }
    if(remainer >= 0) {
      left_bound = mid + 1;
    } else {
      right_bound = mid - 1;
    }
  }
  cout << right_bound << '\n';
  
  
  return 0;
}

