//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;

ll n, left_pointer, right_pointer, minimum;
vector<ll> acid;
pair<ll, ll> answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  minimum = LONG_LONG_MAX;
  
  cin >> n;
  acid = vector<ll>(n);
  for(ll i = 0; i < n; i++) {
    cin >> acid[i];
  }
  sort(acid.begin(), acid.end());
  left_pointer = 0;
  right_pointer = acid.size() - 1;
  while(left_pointer < right_pointer) {
    if(abs(acid[left_pointer] + acid[right_pointer]) < minimum) {
      minimum = abs(acid[left_pointer] + acid[right_pointer]);
      answer = {acid[left_pointer], acid[right_pointer]};
    }
    if(acid[left_pointer] + acid[right_pointer] < 0) {
      left_pointer++;
    } else {
      right_pointer--;
    }
  }
  cout << answer.first << ' ' << answer.second << '\n';
  
  return 0;
}

