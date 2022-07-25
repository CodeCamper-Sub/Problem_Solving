//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

ll n, x;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> x;
    switch (x) {
      case 0:
        if(q.empty()) {
          cout << 0 << '\n';
        } else {
          cout << q.top() << '\n';
          q.pop();
        }
        break;
      default:
        q.push(x);
        break;
    }
  }
  
  
  return 0;
}

