//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <numeric>
typedef long long ll;
using namespace std;

ll n, numerator, denominator;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> denominator;
  for(ll i = 1; i < n; i++) {
    cin >> numerator;
    cout << denominator / gcd(denominator, numerator) << "/" << numerator / gcd(denominator, numerator) << '\n';
  }
  
  return 0;
}

