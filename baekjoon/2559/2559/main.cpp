//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, k, t;
ll sum[100100], maximum;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  maximum = LONG_LONG_MIN;
  cin >> n >> k;
  for(ll i = 1; i <= n; i++) {
    cin >> t;
    sum[i] = sum[i-1] + t;
  }
  for(ll i = 0; i + k <= n; i++) {
    maximum = max(maximum, sum[i+k] - sum[i]);
  }
  cout << maximum << '\n';
  
  return 0;
}

