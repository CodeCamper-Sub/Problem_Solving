//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, a, carrier;

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
  carrier = 0;
  stack<ll> s;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a;
    s.push(a);
  }
  while(!s.empty() && s.top() == 0) {
    s.pop();
  }
  while(!s.empty()) {
    carrier -= s.top();
    s.pop();
    if(!s.empty() && carrier <= 0) {
      cout << "NO\n";
      return;
    }
  }
  if(carrier == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
