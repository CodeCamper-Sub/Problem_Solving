//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll n;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cout << n * 2 << '\n';
  string answer;
  for(ll i = 1; i <= (n * 2) / 8; i++) {
    answer += '4';
  }
  if((n * 2) % 8) {
    char leading = '0' + ((n * 2) % 8) / 2;
    answer = leading + answer;
  }
  cout << answer << '\n';
  
  return 0;
}
