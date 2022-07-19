//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll a, b;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(true) {
    cin >> a >> b;
    if(a == 0 && b == 0) {
      return 0;
    }
    if(a < b && b % a == 0) {
      cout << "factor\n";
    } else if(a > b && a % b == 0) {
      cout << "multiple\n";
    } else {
      cout << "neither\n";
    }
  }
  
  return 0;
}

