//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, m;

ll get_num_two(ll num) {
  ll num_two = 0;
  for(ll i = 2; i <= num; i *= 2) {
    num_two += num / i;
  }
  return num_two;
}

ll get_num_five(ll num) {
  ll num_five = 0;
  for(ll i = 5; i <= num; i *= 5) {
    num_five += num / i;
  }
  return num_five;
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  
  ll num_two = get_num_two(n) - get_num_two(n-m) - get_num_two(m);
  ll num_five = get_num_five(n) - get_num_five(n-m) - get_num_five(m);
  num_two = max(0ll, num_two);
  num_five = max(0ll, num_five);
  cout << min(num_two, num_five) << '\n';
  
  return 0;
}

