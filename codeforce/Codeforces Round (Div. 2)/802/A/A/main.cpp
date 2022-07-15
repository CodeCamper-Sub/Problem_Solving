//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll sum(ll);

void testcase();

ll tt, n, m, result;

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
  cin >> n >> m;
  result = sum(m) + sum(n) * m - m;
  cout << result << '\n';
}

ll sum(ll end) {
  return end * (end + 1) / 2;
}

