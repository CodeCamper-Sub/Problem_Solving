//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll k, h, m;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> k;
  h = k / 60;
  m = k % 60;
  if(m < 10) {
    cout << 21+h << ":0" << m << '\n';
  } else {
    cout << 21+h << ":" << m << '\n';
  }
  
  return 0;
}

