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

ll tt, n;
ll min_mike, min_joe;
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
  min_mike = INF;
  min_joe = INF;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(i % 2 == 1) {
      min_mike = min(min_mike, a[i]);
    } else {
      min_joe = min(min_joe, a[i]);
    }
  }
  if(n % 2 == 1) {
    cout << "Mike\n";
  } else if (min_mike > min_joe) {
    cout << "Mike\n";
  } else if (min_mike < min_joe) {
    cout << "Joe\n";
  } else {
    for(int i = 1; i <= n; i++) {
      if(i % 2 == 1 && min_mike == a[i]) {
        cout << "Joe\n";
        break;
      } else if(i % 2 == 0 && min_joe == a[i]) {
        cout << "Mike\n";
        break;
      }
    }
  }
}
