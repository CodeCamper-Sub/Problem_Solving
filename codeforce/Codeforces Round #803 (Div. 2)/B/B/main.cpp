//
//  main.cpp
//  B
//
//  Created by CodeCamper on 2022/07/08.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll t, n, k;
ll a[200200];

ll number_of_tall() {
  ll result = 0;
  for(ll i = 2; i < n; i++) {
    if(a[i] > a[i-1] + a[i+1]) {
      result++;
    }
  }
  return result;
}

void testcase() {
  cin >> n >> k;
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if(k == 1) {
    cout << ((n-3)/2) + 1 << '\n';
  } else {
    cout << number_of_tall() << '\n';
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
