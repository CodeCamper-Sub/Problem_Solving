//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n;
ll num_two, num_five;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++){
    ll now = i;
    while(now % 2 == 0) {
      now /= 2;
      num_two++;
    }
    while(now % 5 == 0) {
      now /= 5;
      num_five++;
    }
  }
  cout << min(num_five, num_two) << '\n';
  
  return 0;
}

