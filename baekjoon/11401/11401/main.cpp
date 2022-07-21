//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <tuple>
#include <algorithm>
#define MODULO 1000000007
typedef long long ll;
using namespace std;

ll n, k;
ll factorial[5005000], numerator, denominator, reverse_denominator;

tuple<ll, ll, ll> xGCD(ll a, ll b) {
  if(b == 0) return {a, 1, 0};
  tuple<ll, ll, ll> result = xGCD(b, a % b);
  ll g, x, y;
  g = get<0>(result);
  x = get<2>(result);
  y = get<1>(result) - (a / b) * get<2>(result);
  return {g, x, y};
}

ll reverse_modulo(ll a) {
  ll ret = 0;
  for(ll k = 0; k <= (a * MODULO - 2) / MODULO + 1; k++) {
    if((1 + k * MODULO) % a == 0) {
      ret = (1 + k * MODULO) / a;
      break;
    }
  }
  return ret;
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  
  factorial[0] = 1;
  factorial[1] = 1;
  for(ll i = 2; i <= 5000000; i++) {
    factorial[i] = (factorial[i-1] * i) % MODULO;
  }
  
  numerator = factorial[n];
  denominator = (factorial[n-k] * factorial[k]) % MODULO;
  reverse_denominator = get<1>(xGCD(denominator, MODULO));
  reverse_denominator = reverse_denominator < 0 ? reverse_denominator + MODULO : reverse_denominator;
  cout << (numerator * reverse_denominator) % MODULO << '\n';
  
  return 0;
}

