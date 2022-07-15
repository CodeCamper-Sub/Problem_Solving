//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, c;
string s, result;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    testcase();
  }
  return 0;
}

void testcase() {
  cin >> n;
  cin >> s;
  c = 0;
  result = "";
  if(s[0] == '1') {
    // make 99..99
    for(int i = s.size()-1; i >= 0; i--) {
      int now = s[i] - '0';
      result = to_string(9 - now) + result;
    }
  } else {
    // make 11..11
    for(int i = s.size()-1; i >= 0; i--) {
      int now = s[i] - '0';
      if(now + c > 1) {
        result = to_string(11 - now - c) + result;
        c = 1;
      } else {
        result = to_string(1 - now - c) + result;
        c = 0;
      }
    }
  }
  cout << result << '\n';
}

