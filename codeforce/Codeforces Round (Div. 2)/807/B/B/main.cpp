//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll tt, n, a, sum, answer;

void testcase() {
  sum = 0;
  answer = 0;
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> a;
    if(sum == 0 && a == 0) {
      continue;
    }
    if(i == n) {
      break;
    }
    if(a == 0) {
      answer++;
    }
    sum += a;
  }
  answer += sum;
  cout << answer << '\n';
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> tt;
  while(tt--) {
    testcase();
  }
  
  return 0;
}


