//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, x, answer;
ll a[200200];

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
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  x = a[0];
  for(int i = 1; i < n; i++) {
    if(a[i] > a[i-1]) {
      answer += a[i] - a[i-1];
    } else if(a[i] < a[i-1]){
      answer += a[i-1] - a[i];
      x -= a[i-1] - a[i];
    }
  }
  answer += abs(x);
  cout << answer << '\n';
}
