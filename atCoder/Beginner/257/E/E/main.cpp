//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, c[20];
ll min_c, min_c_index, left_n, num[20];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  min_c = LONG_LONG_MAX;
  cin >> n;
  for(ll i = 1; i <= 9; i++) {
    cin >> c[i];
    if(min_c >= c[i]) {
      min_c = c[i];
      min_c_index = i;
    }
  }
  num[min_c_index] += n / min_c;
  left_n = n % min_c;
  for(ll i = 9; i > min_c_index; i--) {
    if(c[i] - min_c <= left_n) {
      num[i] += left_n / (c[i] - min_c);
      num[min_c_index] -= num[i];
      left_n = left_n % (c[i] - min_c);
    }
  }
  for(ll i = 9; i >= 1; i--) {
    for(ll j = 1; j <= num[i]; j++) {
      cout << i;
    }
  }
  
  return 0;
}

