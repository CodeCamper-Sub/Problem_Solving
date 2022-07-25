//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
#include <deque>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, k;
string p;

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
  cin >> p;
  cin >> n;
  bool reversed = false;
  deque<ll> d;
  char trash;
  
  cin >> trash;
  for(ll i = 1; i <= n; i++) {
    if(i > 1) {
      cin >> trash;
    }
    cin >> k;
    d.push_back(k);
  }
  cin >> trash;
  
  for(ll i = 0; i < p.size(); i++) {
    if(p[i] == 'R') {
      reversed = !reversed;
    } else {
      if(d.empty()) {
        cout << "error\n";
        return;
      }
      if(!reversed) {
        d.pop_front();
      } else {
        d.pop_back();
      }
    }
  }
  if(!reversed) {
    cout << "[";
    for(ll i = 0; i < d.size(); i++) {
      if(i > 0) {
        cout << ",";
      }
      cout << d[i];
    }
    cout << "]\n";
  } else {
    cout << "[";
    for(ll i = d.size() - 1; i >= 0; i--) {
      if(i < d.size() - 1) {
        cout << ",";
      }
      cout << d[i];
    }
    cout << "]\n";
  }
}

