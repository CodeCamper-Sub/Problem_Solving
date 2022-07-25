//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, s, arr[100100], answer;
ll left_pointer, right_pointer, psum;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  answer = LONG_LONG_MAX;
  cin >> n >> s;
  for(ll i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  if(s == 0) {
    cout << 1 << '\n';
    return 0;
  }
  left_pointer = 1;
  right_pointer = 1;
  psum = arr[1];
  while(left_pointer <= n && right_pointer <= n) {
    if(psum >= s) {
      answer = min(answer, right_pointer - left_pointer + 1);
      psum -= arr[left_pointer++];
    } else {
      if(right_pointer < n) {
        psum += arr[++right_pointer];
      } else {
        break;
      }
    }
  }
  if(answer == LONG_LONG_MAX) {
    cout << 0 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}

