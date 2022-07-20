//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, e[100100], v[100100];
ll sum[100100], minimum, answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  minimum = LONG_LONG_MAX;
  cin >> n;
  for(ll i = 1; i < n; i++) {
    cin >> e[i];
  }
  for(ll i = 1; i <= n; i++) {
    cin >> v[i];
    minimum = min(v[i], minimum);
    v[i] = minimum;
  }
  for(ll i = 1; i < n; i++) {
    answer += v[i] * e[i];
  }
  cout << answer << '\n';
  
  return 0;
}

