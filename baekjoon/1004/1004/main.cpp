//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

void testcase();

ll tt, x1, y1, x2, y2, cx, cy, r, n, answer;

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
  answer = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> cx >> cy >> r;
    bool include_start = r * r >= (x1-cx)*(x1-cx) + (y1-cy)*(y1-cy);
    bool include_end = r * r >= (x2-cx)*(x2-cx) + (y2-cy)*(y2-cy);
    if(include_start != include_end) {
      answer++;
    }
  }
  cout << answer << '\n';
}

