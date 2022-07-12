//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

void testcase();

ll tt, a, b;

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
  cin >> a >> b;
  if(a < b && b > 0) {
    cout << 1;
    b--;
  }
  while(a != 0 || b != 0) {
    if(a > 0) {
      cout << 0;
      a--;
    }
    if(b > 0) {
      cout << 1;
      b--;
    }
  }
  cout << '\n';
}
