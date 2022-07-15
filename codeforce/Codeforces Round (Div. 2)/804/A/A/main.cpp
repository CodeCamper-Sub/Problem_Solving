//
//  main.cpp
//  A
//
//  Created by CodeCamper on 2022/07/06.
//

#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll T, n, a, b, c;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--) {
    cin >> n;
    if(n % 2 == 1) {
      cout << "-1\n";
    } else {
      a = n / 2;
      b = 0;
      c = 0;
      cout << a << " " << b << " " << c << '\n';
    }
  }
  return 0;
}
