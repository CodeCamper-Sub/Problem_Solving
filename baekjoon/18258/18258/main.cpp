//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

ll n, x;
string command;
queue<ll> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> command;
    if(command.compare("push") == 0) {
      cin >> x;
      q.push(x);
    } else if(command.compare("pop") == 0) {
      if(!q.empty()) {
        cout << q.front() << '\n';;
        q.pop();
      } else {
        cout << "-1\n";
      }
    } else if(command.compare("size") == 0) {
      cout << q.size() << '\n';
    } else if(command.compare("empty") == 0) {
      cout << int(q.empty()) << '\n';
    } else if(command.compare("front") == 0) {
      if(!q.empty()) {
        cout << q.front() << '\n';
      } else {
        cout << "-1\n";
      }
    } else if(command.compare("back") == 0) {
      if(!q.empty()) {
        cout << q.back() << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }
  
  return 0;
}
