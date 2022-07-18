//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll n, a[500500];
ll used[8080], sum, quotient, remainder, mean, minimum, maximum, frequency, mode;
vector<ll> modes;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  frequency = LONG_LONG_MIN;
  minimum = LONG_LONG_MAX;
  maximum = LONG_LONG_MIN;
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    used[a[i]+4000]++;
    frequency = max(frequency, used[a[i]+4000]);
    minimum = min(minimum, a[i]);
    maximum = max(maximum, a[i]);
  }
  sort(a, a+n);
  vector<ll> modes;
  for(ll i = 0; i <= 8000; i++) {
    if(used[i] == frequency) {
      modes.push_back(i-4000);
    }
  }
  mode = modes.size() > 1 ? modes[1] : modes[0];
  
  quotient = sum / n;
  remainder = sum % n;
  if(remainder < 0 ) {
    quotient -= 1;
    remainder += n;
  }
  mean = remainder > n / 2 ? quotient + 1 : quotient;
  cout << mean << '\n';
  cout << a[n/2] << '\n';
  cout << mode << '\n';
  cout << maximum - minimum << '\n';
  
  return 0;
}

