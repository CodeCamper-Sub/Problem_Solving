//
//  main.cpp
//  A
//
//  Created by CodeCamper on 2022/07/08.
//

#include <iostream>
using namespace std;

int t, n, a;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a;
    }
    cout << a << '\n';
  }
  
  return 0;
}
