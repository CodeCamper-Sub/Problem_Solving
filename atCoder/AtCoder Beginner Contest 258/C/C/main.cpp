//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll n, q, t, x, start_index, print_index;
string s;


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> q;
  cin >> s;
  for(ll i = 1; i <= q; i++) {
    cin >> t >> x;
    if(t == 1) {
      start_index -= x;
      start_index %= n;
      start_index = start_index < 0 ? start_index + n : start_index;
    } else {
      print_index = start_index + x - 1;
      print_index %= n;
      cout << s[print_index] << '\n';
    }
  }
  
  return 0;
}

