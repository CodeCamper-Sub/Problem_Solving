//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll a, b, c;

ll memo[10001000];

ll power(ll base, ll exponent) {
  if (exponent <= 1) {
    return memo[exponent] = base % c;
  }
  if(exponent < 10000000) {
    if(memo[exponent] != LONG_LONG_MIN)
      return memo[exponent];
    else
      return memo[exponent] = ((power(base, exponent / 2) % c) * (power(base, exponent - exponent / 2) % c)) % c;
  }
  return ((power(base, exponent / 2) % c) * (power(base, exponent - exponent / 2) % c)) % c;
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  for(ll i = 0; i <= 10000000; i++) {
    memo[i] = LONG_LONG_MIN;
  }
  
  cin >> a >> b >> c;
  
  cout << power(a, b);
  
  return 0;
}

