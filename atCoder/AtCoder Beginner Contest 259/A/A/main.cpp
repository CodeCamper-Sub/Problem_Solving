//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, m, x, t, d;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> x >> t >> d;
  
  if(m > x) {
    cout << t;
  } else if(m <= x) {
    cout << t - (x - m) * d;
  }
  
  return 0;
}
