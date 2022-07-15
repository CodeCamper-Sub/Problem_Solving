//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  answer = 1;
  for(ll i = 1; i <= n; i++) {
    answer *= 2;
  }
  cout << answer;
  
  return 0;
}

