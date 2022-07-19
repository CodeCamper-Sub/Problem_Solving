//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll w, h, x, y, p, px, py, answer;
ll r;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> w >> h >> x >> y >> p;
  r = h / 2;
  for(ll i = 1; i <= p; i++) {
    cin >> px >> py;
    if(px >= x && px <= x + w && py >= y && py <= y + h) {
      answer++;
    } else if(r * r >= (px-x)*(px-x) + (py-y-r)*(py-y-r)) {
      answer++;
    } else if(r * r >= (px-x-w)*(px-x-w) + (py-y-r)*(py-y-r)) {
      answer++;
    }
  }
  cout << answer << '\n';
  
  return 0;
}

