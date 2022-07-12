//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#define INF 2100000000
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, m, a, maximum, r, c;

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
  maximum = -INF;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++){
      cin >> a;
      if(a > maximum) {
        maximum = a;
        r = i;
        c = j;
      }
    }
  }
  cout << max(r, n - r + 1) * max(c, m - c + 1) << '\n';
}

